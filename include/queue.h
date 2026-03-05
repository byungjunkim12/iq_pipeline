#pragma once
#include <complex>
#include <memory>
#include <mutex>

template <typename T>
class IQQueue{
private:
    std::unique_ptr<T[]> buffer_;
    size_t capacity_;
    size_t size_;
    std::mutex mutex_;

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
        std::lock_guard<std::mutex> lock(mutex_);
        if (size_ >= capacity_) return;
        buffer_[size_++] = item;
    }

    void push(T&& item) {
        std::lock_guard<std::mutex> lock(mutex_);
        if (size_ >= capacity_) return;
        buffer_[size_++] = std::move(item);
    }

    T pop() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (size_ == 0) return T{};
        return buffer_[--size_];
    }
    
    bool empty() const { return (size_ == 0); };
};

