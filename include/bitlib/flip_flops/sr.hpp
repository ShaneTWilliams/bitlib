#pragma once

#include "bitlib/core/component.hpp"
#include "bitlib/gates/and.hpp"
#include "bitlib/gates/buffer.hpp"
#include "bitlib/gates/nor.hpp"
#include "bitlib/latches/sr.hpp"

namespace bl {

class SrFlipFlop : public Component {
 public:
    SrFlipFlop(std::string name);

    InputNode* s;
    InputNode* r;
    InputNode* en;
    OutputNode* q;
    OutputNode* qn;

 private:
    SrLatch sr_latch;
    AndGate<2> s_and;
    AndGate<2> r_and;
    BufferGate en_buf;
};

}  // namespace bl
