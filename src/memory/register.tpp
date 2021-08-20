#pragma once

#include <string>

namespace bl {

template <uint8_t NUM_BITS>
Register<NUM_BITS>::Register(std::string name) : Component(name), data(0) {
    static_assert(NUM_BITS <= sizeof(this->data) * 8);
    for (uint16_t i = 0; i < NUM_BITS; i++) {
        this->bits.push_back(RegisterBit(name + "::BIT_" + std::to_string(i)));
    }
}

}  // namespace bl
