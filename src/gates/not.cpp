#include "bitlib/gates/not.hpp"

bl::NotGate::NotGate(std::string name)
    : Primitive(name),
      input(InputNode::create_new(State::LOW, &(this->update_state), name + "::INPUT")),
      output(OutputNode::create_new(State::HIGH, &(this->update_state), name + "::OUTPUT")) {}

void bl::NotGate::update_state(void) { this->output->set_state(!this->input->get_state()); }
