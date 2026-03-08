#include <gtest/gtest.h>
#include <complex>
#include "queue.h"

TEST(IQQueueTest, TEST12) {
    IQQueue<std::complex<float>> queue(10);
    std::complex<float> c0{1.0f, 2.0f};
    std::complex<float> c1;
    queue.push(c0);
    queue.pop(c1);
    EXPECT_EQ(c0, c1);
    EXPECT_TRUE(queue.empty());
}

TEST(IQQueueTest, FIFOOrdering) {
    IQQueue<std::complex<float>> queue(10);
    std::vector<std::complex<float>> c_vec = {
        {1.0f, 2.0f},
        {2.0f, 3.0f},
        {3.0f, 4.0f}};
    for (int i = 0; i < 3; i++){
        queue.push(c_vec[i]);
    }
    
    std::complex<float> c;
    for (int i = 0; i < 3; i++) {
        queue.pop(c);
        EXPECT_EQ(c_vec[i], c);
    }
    
    queue.set_done();
    EXPECT_FALSE(queue.pop(c));
}

