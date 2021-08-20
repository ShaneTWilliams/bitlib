#include "bitlib/core/bit_flip_queue.hpp"

bl::BitFlip bl::BitFlipQueue::front(void) {
    std::unique_lock<std::mutex> lock(this->mutex);
    return this->queue.front();
}

bl::BitFlip bl::BitFlipQueue::back(void) {
    std::unique_lock<std::mutex> lock(this->mutex);
    return this->queue.back();
}

void bl::BitFlipQueue::push(BitFlip bit_flip) {
    std::unique_lock<std::mutex> lock(this->mutex);
    this->queue.push(bit_flip);
}

void bl::BitFlipQueue::pop(void) {
    std::unique_lock<std::mutex> lock(this->mutex);
    this->queue.pop();
}

int bl::BitFlipQueue::size(void) {
    std::unique_lock<std::mutex> lock(this->mutex);
    return this->queue.size();
}

bool bl::BitFlipQueue::empty(void) {
    std::unique_lock<std::mutex> lock(this->mutex);
    return this->queue.empty();
}
