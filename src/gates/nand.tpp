#pragma once

namespace bl {

template <uint16_t NUM_INPUTS>
bl::NandGate<NUM_INPUTS>::NandGate(std::string name) : bl::MultiInputGate<NUM_INPUTS>(name) {}

template <uint16_t NUM_INPUTS>
void bl::NandGate<NUM_INPUTS>::update(void) {
    State output_state = State::LOW;
    for (InputNode* input : this->inputs) {
        if (input->get_state() == State::LOW) {
            output_state = State::HIGH;
            break;
        }
    }
    this->output->set_state(output_state);
}

}  // namespace bl
