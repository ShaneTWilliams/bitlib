#pragma once

#include "bitlib/gates/single_input_gate.hpp"

namespace bl {

class NotGate : public SingleInputGate {
 public:
    NotGate(std::string name);

    void update(void);
};

}  // namespace bl
