#pragma once

namespace bl {

template <uint16_t NUM_INPUTS>
bl::AndGate<NUM_INPUTS>::AndGate(std::string name) : BaseGate<NUM_INPUTS>(name) {}

template <uint16_t NUM_INPUTS>
void bl::AndGate<NUM_INPUTS>::update_state(void) {
    State output_state = State::HIGH;
    for (InputNode* input : this->inputs) {
        if (input->get_state() == State::LOW) {
            output_state = State::LOW;
            break;
        }
    }
    this->output->set_state(output_state);
}

}  // namespace bl
