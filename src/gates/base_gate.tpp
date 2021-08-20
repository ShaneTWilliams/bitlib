#pragma once

#include <string>

namespace bl {

template <uint16_t NUM_INPUTS>
bl::BaseGate<NUM_INPUTS>::BaseGate(std::string name) : Primitive(name) {
    output = OutputNode::create_new(State::LOW, &(this->update_state), name + "::OUTPUT");
    for (uint16_t i = 0; i < NUM_INPUTS; i++) {
        std::string input_name = name + "::INPUT_" + std::to_string(i);
        this->inputs.push_back(InputNode::create_new(State::LOW, &(this->update_state), input_name));
    }
}

}  // namespace bl
