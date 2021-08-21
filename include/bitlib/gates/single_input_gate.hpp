#pragma once

#include <vector>

#include "bitlib/core/node.hpp"
#include "bitlib/core/primitive.hpp"

namespace bl {

class SingleInputGate : public Primitive {
 public:
    SingleInputGate(std::string name);

    InputNode* input;
    OutputNode* output;
};

}  // namespace bl
