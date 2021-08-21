#include "bitlib/gates/not.hpp"

bl::NotGate::NotGate(std::string name) : SingleInputGate(name) {}

void bl::NotGate::update(void) { this->output->set_state(!this->input->get_state()); }
