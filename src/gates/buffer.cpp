#include "bitlib/gates/buffer.hpp"

bl::BufferGate::BufferGate(std::string name) : SingleInputGate(name) {}

void bl::BufferGate::update(void) { this->output->set_state(this->input->get_state()); }
