#pragma once

#include "bitlib/gates/base_gate.hpp"

namespace bl {

template <uint16_t NUM_INPUTS>
class OrGate : public BaseGate<NUM_INPUTS> {
 public:
    OrGate(std::string name);

    void update_state(void);
};

}  // namespace bl

#include "src/gates/or.tpp"
