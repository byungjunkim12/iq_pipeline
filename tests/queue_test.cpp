#include <gtest/gtest.h>
#include "queue.h"
#include <complex>

TEST(IQQueueTest, PushPopReturnsSameValue) {
    IQQueue<std::complex<float>> queue(100);
    std::complex<float> c0{1.0, 1.0};
    queue.push(c0);
    std::complex<float> c1;
    queue.pop(c1);
    
    EXPECT_EQ(c0, c1);
}

TEST(IQQueueTest, EmptyAfterPushPop) {
    IQQueue<std::complex<float>> queue(100);
    std::complex<float> c0{1.0, 1.0};
    queue.push(c0);
    std::complex<float> c1;
    queue.pop(c1);

    EXPECT_TRUE(queue.empty());
}

TEST(IQQueueTest, FIFOOrdering) {
    IQQueue<std::complex<float>> queue(100);
    for (int i = 0; i < 2; i++) {
        std::complex<float> c{i * 1.0f, i * 1.0f};
        queue.push(c);
    }
    std::complex<float> dump;
    for (int i = 0; i < 2; i++) {
        queue.pop(dump);
        std::complex<float> expected{i*1.0f, i*1.0f};
        EXPECT_EQ(expected, dump);
    }
}

TEST(IQQueueTest, SetDoneReturnsFalse){
    IQQueue<std::complex<float>> queue(100);
    queue.set_done();
    std::complex<float> c;
    EXPECT_FALSE(queue.pop(c));
}
