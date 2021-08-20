#pragma once

#include <mutex>
#include <queue>

#include "bitlib/core/bit_flip.hpp"

namespace bl {

class BitFlipQueue {
 public:
    BitFlip front(void);
    BitFlip back(void);

    void push(BitFlip bit_flip);
    void pop(void);

    int size();
    bool empty();

 private:
    std::queue<BitFlip> queue;
    std::mutex mutex;
};

}  // namespace bl
