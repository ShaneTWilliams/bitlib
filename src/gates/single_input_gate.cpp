#include "bitlib/gates/single_input_gate.hpp"

#include <string>

namespace bl {

bl::SingleInputGate::SingleInputGate(std::string name)
    : Primitive(name),
      input(InputNode::create_new(State::LOW, this, name + "::INPUT")),
      output(OutputNode::create_new(State::LOW, this, name + "::OUTPUT")) {}

}  // namespace bl
