#pragma once

#include "bitlib/gates/multi_input_gate.hpp"

namespace bl {

template <uint16_t NUM_INPUTS>
class AndGate : public MultiInputGate<NUM_INPUTS> {
 public:
    AndGate(std::string name);

    void update(void);
};

}  // namespace bl

#include "src/gates/and.tpp"
