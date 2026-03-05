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
    bool done_ = false;
    
    size_t head_;
    size_t tail_;

public:
    IQQueue(size_t capacity) : capacity_(capacity), size_(0), head_(0), tail_(0) { buffer_ = std::make_unique<T[]>(capacity_); }
    
    IQQueue(IQQueue&& other) noexcept : 
        capacity_(other.capacity_),
        size_(other.size_){
        buffer_ = std::move(other.buffer_);
        other.size_ = 0;
        other.capacity_ = 0;
    }

    void push(const T& item) {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return size_ < capacity_; });
        buffer_[tail_] = item;
        tail_ = (tail_ + 1) % capacity_;
        size_++;
        cv_.notify_one();
    }

    void push(T&& item) {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return size_ < capacity_; });
        buffer_[tail_] = std::move(item);
        tail_ = (tail_ + 1) % capacity_;
        size_++;
        cv_.notify_one();
    }

    bool pop(T& item) {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return size_ > 0 || done_; });
        if (empty()) return false;
        item = buffer_[head_];
        head_ = (head_ + 1) % capacity_;
        size_--;
        cv_.notify_one();
        return true;
    }
    
    bool empty() const { return (size_ == 0); };
    
    void set_done() {
        std::unique_lock<std::mutex> lock(mutex_);
        done_ = true;
        cv_.notify_all();
    }
    
    bool is_done() { return done_; }
};

