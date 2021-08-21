#pragma once

#include <cstdint>
#include <vector>

#include "bitlib/core/component.hpp"
#include "bitlib/memory/register_bit.hpp"

namespace bl {

template <uint8_t NUM_BITS>
class Register : public Component {
 public:
    Register(std::string name);

    uint64_t get_data(void);
    static_assert(NUM_BITS <= sizeof(uint64_t) * 8);

    std::vector<RegisterBit> bits;
};

}  // namespace bl

#include "src/memory/register.tpp"
