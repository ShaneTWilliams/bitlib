#include "bitlib/gates/buffer.hpp"

bl::BufferGate::BufferGate(std::string name)
    : Primitive(name),
      input(InputNode::create_new(State::LOW, &(this->update_state), name + "::INPUT")),
      output(OutputNode::create_new(State::LOW, &(this->update_state), name + "::OUTPUT")) {}

void bl::BufferGate::update_state(void) { this->output->set_state(this->input->get_state()); }
