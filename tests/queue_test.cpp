#include <gtest/gtest.h>
#include "queue.h"
#include <complex>

TEST(IQQueueTest, PushPopReturnsSameValue) {
    IQQueue<std::complex<float>> queue(10);
    std::complex<float> a{1.0, 2.0};
    queue.push(a);
    std::complex<float> b;
    queue.pop(b);
    EXPECT_EQ(a, b);
}

TEST(IQQueueTest, EmptyAfterPushPop) {
    IQQueue<std::complex<float>> queue(10);
    std::complex<float> a{1.0, 2.0};
    queue.push(a);
    queue.pop(a);
    EXPECT_TRUE(queue.empty());
}

TEST(IQQueueTest, FIFOOrdering) {
    IQQueue<std::complex<float>> queue(10);
    std::vector<std::complex<float>> c_vec{
        {1.0, 2.0},
        {2.0, 3.0},
        {3.0, 4.0}};
        
    for (int i = 0; i < 3; i++)
        queue.push(c_vec[i]);
    
    for (int i = 0; i < 3; i++){
        std::complex<float> b;
        queue.pop(b);
        EXPECT_EQ(c_vec[i], b);
    }
}
    
TEST(IQQueueTest, SetDoneReturnsFalse){ 
    IQQueue<std::complex<float>> queue(10);
    std::complex<float> a;
    queue.set_done();
    EXPECT_FALSE(queue.pop(a));
}

