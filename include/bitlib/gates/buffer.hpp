#pragma once

#include "bitlib/core/node.hpp"
#include "bitlib/core/primitive.hpp"

namespace bl {

class BufferGate : public Primitive {
 public:
    BufferGate(std::string name);

    void update_state(void);

    InputNode* input;
    OutputNode* output;
};

}  // namespace bl
