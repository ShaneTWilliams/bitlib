#pragma once

#include <string>

namespace bl {

template <uint16_t NUM_INPUTS>
bl::MultiInputGate<NUM_INPUTS>::MultiInputGate(std::string name) : Primitive(name) {
    output = OutputNode::create_new(State::LOW, this, name + "::OUTPUT");
    for (uint16_t i = 0; i < NUM_INPUTS; i++) {
        this->inputs.push_back(
            InputNode::create_new(State::LOW, this, name + "::INPUT_" + std::to_string(i)));
    }
}

}  // namespace bl
