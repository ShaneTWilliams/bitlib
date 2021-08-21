#include "bitlib/sources/single_source.hpp"

bl::SingleSource::SingleSource(std::string name)
    : Primitive(name), output(OutputNode::create_new(State::LOW, this, name)) {}

void bl::SingleSource::update(void) {}

bool bl::SingleSource::has_unconnected(void) { return this->output->connections.empty(); }

void bl::SingleSource::set_output(bl::State state) { this->output->set_state(state); }

bl::State bl::SingleSource::get_output(void) { return this->output->get_state(); }
