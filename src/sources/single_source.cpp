#include "bitlib/sources/single_source.hpp"

bl::SingleSource::SingleSource(std::string name)
    : Primitive(name), output(OutputNode::create_new(State::LOW, &(this->update_state), name + "::OUTPUT")) {}

void bl::SingleSource::update_state(void) { output->set_state(this->state); }

bool bl::SingleSource::has_unconnected(void) { return this->output->connections.empty(); }

void bl::SingleSource::set_output(bl::State state) {
    this->state = state;
    &(this->update_state)();
}

bl::State bl::SingleSource::get_output(void) { return this->state; }
