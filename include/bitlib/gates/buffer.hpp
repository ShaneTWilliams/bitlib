#pragma once

#include "bitlib/gates/single_input_gate.hpp"

namespace bl {

class BufferGate : public SingleInputGate {
 public:
    BufferGate(std::string name);

    void update(void);
};

}  // namespace bl
