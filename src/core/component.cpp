#include "bitlib/core/component.hpp"

bl::Component::Component(std::string name) : name(name), label("") {}

std::string bl::Component::get_name(void) { return this->name; }

std::string bl::Component::get_label(void) { return this->label; }

void bl::Component::set_label(std::string label) { this->label = label; }
