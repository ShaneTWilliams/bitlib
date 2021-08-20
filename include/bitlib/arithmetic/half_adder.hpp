#pragma once

#include "bitlib/core/component.hpp"
#include "bitlib/gates/and.hpp"
#include "bitlib/gates/buffer.hpp"
#include "bitlib/gates/xor.hpp"

namespace bl {

class HalfAdder : public Component {
 public:
    HalfAdder(std::string name);

    InputNode* a;
    InputNode* b;
    OutputNode* sum;
    OutputNode* carry;

 private:
    AndGate<2> and_gate;
    XorGate<2> xor_gate;
    BufferGate a_buf_gate;
    BufferGate b_buf_gate;
};

}  // namespace bl
