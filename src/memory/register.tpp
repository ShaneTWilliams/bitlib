#pragma once

#include <string>

namespace bl {

template <uint8_t NUM_BITS>
Register<NUM_BITS>::Register(std::string name) : Component(name) {
    this->bits.reserve(NUM_BITS);
    for (uint16_t i = 0; i < NUM_BITS; i++) {
        this->bits.emplace_back(name + "::BIT_" + std::to_string(i));
    }
}

template <uint8_t NUM_BITS>
uint64_t Register<NUM_BITS>::get_data(void) {
    uint64_t data = 0;
    for (uint16_t i = 0; i < NUM_BITS; i++) {
        if (this->bits[i].output->get_state() == State::HIGH) {
            data |= 1 << i; 
        }
    }
    return data;
}

}  // namespace bl
