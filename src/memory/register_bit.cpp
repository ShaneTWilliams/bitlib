#include "bitlib/memory/register_bit.hpp"

bl::RegisterBit::RegisterBit(std::string name) : Primitive(name) {
    input = bl::InputNode::create_new(bl::State::LOW, this, name + "::INPUT");
    output = bl::OutputNode::create_new(bl::State::LOW, this, name + "::OUTPUT");
}

void bl::RegisterBit::update(void) { this->output->set_state(this->input->get_state()); }
