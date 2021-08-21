#pragma once

#include "bitlib/gates/multi_input_gate.hpp"

namespace bl {

template <uint16_t NUM_INPUTS>
class NandGate : public MultiInputGate<NUM_INPUTS> {
 public:
    NandGate(std::string name);

    void update(void);
};

}  // namespace bl

#include "src/gates/nand.tpp"
