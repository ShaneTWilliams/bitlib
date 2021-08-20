#pragma once

#include <vector>

#include "bitlib/core/node.hpp"
#include "bitlib/core/primitive.hpp"

namespace bl {

template <uint16_t NUM_INPUTS>
class BaseGate : public Primitive {
 public:
    BaseGate(std::string name);

    virtual void update_state(void) = 0;

    std::vector<InputNode*> inputs;
    OutputNode* output;
};

}  // namespace bl

#include "src/gates/base_gate.tpp"
