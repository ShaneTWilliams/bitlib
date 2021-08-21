#pragma once

#include "bitlib/arithmetic/full_adder.hpp"
#include "bitlib/core/component.hpp"

namespace bl {

template <uint8_t NUM_BITS>
class RippleAdder : public Component {
 public:
    static_assert(NUM_BITS > 0);
    RippleAdder(std::string name);

    std::vector<InputNode*> input_a_bits;
    std::vector<InputNode*> input_b_bits;
    std::vector<OutputNode*> sum_bits;
    InputNode* carry_in;
    OutputNode* carry_out;

 private:
    std::vector<FullAdder> adders;
};

}  // namespace bl

#include "src/arithmetic/ripple_adder.tpp"
