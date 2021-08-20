#pragma once

#include <string>

namespace bl {

class Component {
 public:
    Component(std::string full_name);

    std::string get_name(void);

    std::string full_name;
    std::string pretty_name;
};

}  // namespace bl
