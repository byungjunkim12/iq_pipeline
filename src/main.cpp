#include <thread>
#include <complex>
#include "queue.h"

void producer(IQQueue<std::complex<float>>& queue, int num_samples);
void consumer(IQQueue<std::complex<float>>& queue, int num_samples);

int main (void) {
    IQQueue<std::complex<float>> queue(100);
    std::thread t0(producer, std::ref(queue), 10);
    std::thread t1(consumer, std::ref(queue), 10);
    
    t0.join();
    t1.join();
}
