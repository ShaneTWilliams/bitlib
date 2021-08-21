#pragma once

#include <vector>

#include "bitlib/core/node.hpp"
#include "bitlib/core/primitive.hpp"

namespace bl {

template <uint16_t NUM_INPUTS>
class MultiInputGate : public Primitive {
 public:
    MultiInputGate(std::string name);

    std::vector<InputNode*> inputs;
    OutputNode* output;
};

}  // namespace bl

#include "src/gates/multi_input_gate.tpp"
