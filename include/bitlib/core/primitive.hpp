#pragma once

#include "bitlib/core/component.hpp"

namespace bl {

class Primitive : public Component {
 public:
    Primitive(std::string name);

    virtual void update(void) = 0;
};

}  // namespace bl
