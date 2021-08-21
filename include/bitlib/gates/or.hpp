#pragma once

#include "bitlib/gates/multi_input_gate.hpp"

namespace bl {

template <uint16_t NUM_INPUTS>
class OrGate : public MultiInputGate<NUM_INPUTS> {
 public:
    OrGate(std::string name);

    void update(void);
};

}  // namespace bl

#include "src/gates/or.tpp"
