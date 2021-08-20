#pragma once

#include "bitlib/core/node.hpp"
#include "bitlib/core/primitive.hpp"

namespace bl {

class RegisterBit : public Primitive {
 public:
    RegisterBit(std::string name);
    virtual ~RegisterBit(void) = default;

    void update_state(void);

    InputNode* input;
    OutputNode* output;
};

}  // namespace bl
