#pragma once

#include "bitlib/arithmetic/half_adder.hpp"
#include "bitlib/core/component.hpp"
#include "bitlib/gates/or.hpp"

namespace bl {

class FullAdder : public Component {
 public:
    FullAdder(std::string name);

    InputNode* a;
    InputNode* b;
    InputNode* carry_in;
    OutputNode* sum;
    OutputNode* carry_out;

 private:
    HalfAdder half_adder_1;
    HalfAdder half_adder_2;
    OrGate<2> or_gate;
};

}  // namespace bl
