#include "bitlib/core/executor.hpp"

#include "bitlib/core/node.hpp"
#include "bitlib/util/logging.hpp"

bl::Executor bl::executor_inst;

void bl::Executor::run(void) {
    for (InputNode node : input_netlist) {
        if (node.is_floating) {
            bl::log::warning << "Floating input node: " << node.get_name();
        }
    }

    bl::log::info << bl::log::green << "Stabilizing circuit.";
    for (OutputNode output_node : output_netlist) {
        for (InputNode* input_node : output_node.connections) {
            input_node->set_state(output_node.get_state());
            input_node->parent->update();
        }
    }

    while (!this->bit_flip_queue.empty()) {
        BitFlip bit_flip = bit_flip_queue.front();
        bit_flip.node->set_state(bit_flip.new_state, false);
        for (InputNode* input_node : bit_flip.node->connections) {
            input_node->set_state(bit_flip.new_state);
        }
        this->bit_flip_queue.pop();
    }

    bl::log::info << bl::log::green << "Running netlist with "
                  << std::to_string(input_netlist.size() + output_netlist.size()) << " elements";
    this->thread = std::thread(&Executor::thread_func, this);
}

void bl::Executor::kill(void) {
    bl::log::info << bl::log::green << "Terminating netlist execution";

    this->kill_thread = true;
    if (this->thread.joinable()) {
        this->thread.join();
    }
}

void bl::Executor::thread_func(void) {
    while (!this->kill_thread) {
        if (this->bit_flip_queue.empty()) {
            continue;
        }
        BitFlip bit_flip = bit_flip_queue.front();
        bit_flip.node->set_state(bit_flip.new_state, false);
        for (InputNode* input_node : bit_flip.node->connections) {
            input_node->set_state(bit_flip.new_state);
        }
        this->bit_flip_queue.pop();
    }
}

void bl::Executor::queue_bit_flip(BitFlip bit_flip) { this->bit_flip_queue.push(bit_flip); }
