#include "bitlib/core/component.hpp"

bl::Component::Component(std::string full_name) : full_name(full_name), pretty_name("") {}

std::string bl::Component::get_name(void) {
    if (!this->pretty_name.empty()) {
        return this->pretty_name;
    }
    return this->full_name;
}
