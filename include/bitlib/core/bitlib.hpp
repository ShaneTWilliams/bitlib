#pragma once

#include <cstdint>

namespace bl {

enum class State : uint8_t { LOW, HIGH };

inline State operator!(State state) {
    if (state == State::HIGH) {
        return State::LOW;
    }
    return State::HIGH;
}

enum class Direction : uint8_t { INPUT, OUTPUT };

enum class IntBase : uint8_t { BINARY, OCTAL, DECIMAL, HEXADECIMAL };

}  // namespace bl
