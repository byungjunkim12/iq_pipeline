#pragma once
#include <complex>

template <typename T>
class IQQueue{
private:
    T* buffer_;
    size_t capacity_;
    size_t size_;

public:
    IQQueue(size_t capacity) : capacity_(capacity), size_(0) { buffer_ = new T[capacity_]; }
    ~IQQueue() { delete[] buffer_; }

    IQQueue(const IQQueue&) = delete;
    IQQueue& operator=(const IQQueue&) = delete;

    void push(const T& item) {
        if (size_ >= capacity_) return;
        buffer_[size_++] = item;
    }

    T pop() {
        if (size_ == 0) return T{};
        return buffer_[--size_];
    }
    
    bool empty() const {
        return (size_ == 0);
    };
};

