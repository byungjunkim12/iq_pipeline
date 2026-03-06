#include <iostream>
#include <complex>
#include <thread>
#include "queue.h"

void producer(IQQueue<std::complex<float>>& queue, int num_samples);
void consumer(IQQueue<std::complex<float>>& queue);

int main(void) {
    IQQueue<std::complex<float>> queue(100);
    std::thread t1(producer, std::ref(queue), 10);
    std::thread t2(consumer, std::ref(queue));
    t1.join();
    t2.join();
}
