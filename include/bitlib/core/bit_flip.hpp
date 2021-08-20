#pragma once

#include "bitlib/core/bitlib.hpp"
#include "bitlib/core/node.hpp"

namespace bl {

typedef struct {
    OutputNode* node;
    State new_state;
} BitFlip;

};  // namespace bl
