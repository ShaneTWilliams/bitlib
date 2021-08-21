#pragma once

#include "bitlib/core/node.hpp"
#include "bitlib/core/primitive.hpp"

namespace bl {

class RegisterBit : public Primitive {
 public:
    RegisterBit(std::string name);

    void update(void);

    InputNode* input;
    OutputNode* output;
};

}  // namespace bl
