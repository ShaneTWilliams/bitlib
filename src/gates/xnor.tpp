#pragma once

namespace bl {

template <uint16_t NUM_INPUTS>
bl::XnorGate<NUM_INPUTS>::XnorGate(std::string name) : BaseGate<NUM_INPUTS>(name) {}

template <uint16_t NUM_INPUTS>
void bl::XnorGate<NUM_INPUTS>::update_state(void) {
    uint16_t count = 0;
    for (InputNode* input : this->inputs) {
        if (input->get_state() == State::HIGH) {
            count++;
        }
    }
    State state = count % 2 == 0 ? State::HIGH : State::LOW;
    this->output->set_state(state);
}

}  // namespace bl
