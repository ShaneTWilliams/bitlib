#include "bitlib/memory/register_bit.hpp"

bl::RegisterBit::RegisterBit(std::string name) : Primitive(name) {
    input = bl::InputNode::create_new(bl::State::LOW, &(this->update_state), name + "::INPUT");
    output = bl::OutputNode::create_new(bl::State::LOW, &(this->update_state), name + "::OUTPUT");
}

void bl::RegisterBit::update_state(void) { this->output->set_state(this->input->get_state()); }
