#pragma once

#include <cstdint>

#include "bitlib/core/primitive.hpp"

namespace bl {

class Scope : public Primitive {
 public:
    Scope(std::string name);

    void update_state(void);
};

}  // namespace bl
