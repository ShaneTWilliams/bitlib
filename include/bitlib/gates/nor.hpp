#pragma once

#include "bitlib/gates/multi_input_gate.hpp"

namespace bl {

template <uint16_t NUM_INPUTS>
class NorGate : public MultiInputGate<NUM_INPUTS> {
 public:
    NorGate(std::string name);

    void update(void);
};

}  // namespace bl

#include "src/gates/nor.tpp"
