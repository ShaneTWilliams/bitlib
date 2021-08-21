#pragma once

#include <cstdint>

#include "bitlib/core/node.hpp"
#include "bitlib/core/primitive.hpp"

namespace bl {

class SingleSource : public Primitive {
 public:
    SingleSource(std::string name);

    void update(void);
    bool has_unconnected(void);

    void set_output(State state);
    State get_output(void);

    OutputNode* output;
};

}  // namespace bl
