#pragma once
#include <complex>
#include <memory>
#include <mutex>
#include <condition_variable>

template <typename T>
class IQQueue{
private:
    std::unique_ptr<T[]> buffer_;
    size_t capacity_;
    size_t size_;
    std::mutex mutex_;
    std::condition_variable cv_;

public:
    IQQueue(size_t capacity) : capacity_(capacity), size_(0) { buffer_ = std::make_unique<T[]>(capacity_); } 
    IQQueue(IQQueue&& other) noexcept :
        capacity_(other.capacity_),
        size_(other.size_),
        buffer_(std::move(other.buffer_)) {
        other.capacity_ = 0;
        other.size_ = 0;
    }

    void push(const T& item) {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return size_ < capacity_; });
        buffer_[size_++] = item;
        cv_.notify_one();
    }

    void push(T&& item) {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return size_ < capacity_; });
        buffer_[size_++] = std::move(item);
        cv_.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return !empty(); });
        return buffer_[--size_];
    }
    
    bool empty() const { return (size_ == 0); };
};

