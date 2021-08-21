#pragma once

#include <string>

namespace bl {

class Component {
 public:
    Component(std::string name);

    std::string get_name(void);
    std::string get_label(void);
    void set_label(std::string);

 protected:
    std::string name;
    std::string label;
};

}  // namespace bl
