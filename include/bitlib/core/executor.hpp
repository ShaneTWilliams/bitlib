#pragma once

#include <thread>

#include "bitlib/core/bit_flip_queue.hpp"

namespace bl {

class Executor {
 public:
    void run(void);
    void kill(void);
    void queue_bit_flip(BitFlip bit_flip);

 private:
    void thread_func(void);

    BitFlipQueue bit_flip_queue;
    std::thread thread;
    bool kill_thread = false;
};

extern Executor executor_inst;

}  // namespace bl
