#pragma once

namespace bl {

template <uint16_t NUM_INPUTS>
bl::OrGate<NUM_INPUTS>::OrGate(std::string name) : bl::MultiInputGate<NUM_INPUTS>(name) {}

template <uint16_t NUM_INPUTS>
void bl::OrGate<NUM_INPUTS>::update(void) {
    State output_state = State::LOW;
    for (InputNode* input : this->inputs) {
        if (input->get_state() == State::HIGH) {
            output_state = State::HIGH;
            break;
        }
    }
    this->output->set_state(output_state);
}

}  // namespace bl
