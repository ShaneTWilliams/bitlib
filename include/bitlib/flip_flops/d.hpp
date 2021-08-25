#pragma once

#include "bitlib/core/component.hpp"
#include "bitlib/flip_flops/sr.hpp"
#include "bitlib/gates/buffer.hpp"
#include "bitlib/gates/not.hpp"

namespace bl {

class DFlipFlop : public Component {
 public:
    DFlipFlop(std::string name);

    InputNode* d;
    InputNode* clk;
    OutputNode* q;
    OutputNode* qn;

 private:
    SrFlipFlop sr_flip_flop;
    BufferGate d_buf;
    NotGate d_not;
};

}  // namespace bl
