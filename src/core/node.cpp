#include "bitlib/core/node.hpp"

#include <algorithm>
#include <iomanip>

#include "bitlib/core/executor.hpp"
#include "bitlib/util/logging.hpp"

std::deque<bl::InputNode> bl::input_netlist = std::deque<bl::InputNode>();
std::deque<bl::OutputNode> bl::output_netlist = std::deque<bl::OutputNode>();

bl::Node::Node(bl::Direction direction, bl::State start_state,
               UpdateCallback update_callback, std::string name)
    : Component(name),
      direction(direction),
      update_state(update_callback),
      state(start_state) {}

bl::OutputNode::OutputNode(bl::State start_state, UpdateCallback update_callback,
                           std::string name)
    : Node(Direction::OUTPUT, start_state, update_callback, name) {}

bl::InputNode::InputNode(bl::State start_state, UpdateCallback update_callback,
                         std::string name)
    : Node(Direction::INPUT, start_state, update_callback, name) {}

bl::State bl::Node::get_state(void) { return this->state; }

void bl::connect(InputNode* input_node, OutputNode* output_node) {
    auto node_iter =
        std::find(output_node->connections.begin(), output_node->connections.end(), input_node);
    if (node_iter == output_node->connections.end()) {
        output_node->connections.push_back(input_node);
    }
    input_node->is_floating = false;
}

void bl::disconnect(InputNode* input_node, OutputNode* output_node) {
    auto node_iter =
        std::find(output_node->connections.begin(), output_node->connections.end(), input_node);
    if (node_iter != output_node->connections.end()) {
        output_node->connections.erase(node_iter);
    }
    input_node->is_floating = true;
}

bool bl::is_connected(InputNode* input_node, OutputNode* output_node) {
    auto node_iter =
        std::find(output_node->connections.begin(), output_node->connections.end(), input_node);
    return !(node_iter == output_node->connections.end());
}

void bl::connect(OutputNode* output_node, InputNode* input_node) {
    bl::connect(input_node, output_node);
}

void bl::disconnect(OutputNode* output_node, InputNode* input_node) {
    bl::disconnect(input_node, output_node);
}

bool bl::is_connected(OutputNode* output_node, InputNode* input_node) {
    return bl::is_connected(input_node, output_node);
}

bl::OutputNode* bl::OutputNode::create_new(bl::State start_state, UpdateCallback update_callback,
                                           std::string name) {
    output_netlist.push_back(OutputNode(start_state, update_callback, name));
    return &output_netlist.back();
}

void bl::OutputNode::connect(InputNode* node) { return bl::connect(node, this); }

void bl::OutputNode::disconnect(InputNode* node) { bl::disconnect(node, this); }

bool bl::OutputNode::is_connected(InputNode* node) { return bl::is_connected(node, this); }

void bl::OutputNode::set_state(bl::State state, bool push_to_queue) {
    if (state == this->state) {
        return;
    }
    if (push_to_queue) {
        bl::executor_inst.queue_bit_flip({this, state});
    } else {
        if (this->log_state_changes) {
            bl::log::debug << std::setw(40) << std::left << this->get_name() << std::right
                           << (bool)this->state << " -> " << (bool)state;
        }
        this->state = state;
    }
}

bl::InputNode* bl::InputNode::create_new(bl::State start_state, UpdateCallback update_callback,
                                         std::string name) {
    input_netlist.push_back(InputNode(start_state, update_callback, name));
    return &input_netlist.back();
}

void bl::InputNode::connect(OutputNode* node) { return bl::connect(this, node); }

void bl::InputNode::disconnect(OutputNode* node) { bl::disconnect(this, node); }

bool bl::InputNode::is_connected(OutputNode* node) { return bl::is_connected(this, node); }

void bl::InputNode::set_state(bl::State state) {
    if (state == this->state) {
        return;
    }
    if (this->log_state_changes) {
        bl::log::debug << std::setw(40) << std::left << this->get_name() << std::right
                       << (bool)this->state << " -> " << (bool)state;
    }
    this->state = state;
    &(this->update_state)();
}
