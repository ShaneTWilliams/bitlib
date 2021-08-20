#pragma once

#include <list>

#include "bitlib/core/component.hpp"

namespace bl {

class Primitive : public Component {
 public:
    Primitive(std::string name);

    virtual void update_state(void) = 0;
};

typedef void (Primitive::*UpdateCallback)(void);

}  // namespace bl
