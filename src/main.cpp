#include <iostream>
#include <thread>
#include <complex>
#include "queue.h"

void producer(IQQueue<std::complex<float>>& queue, int num_samples);
void consumer(IQQueue<std::complex<float>>& queue, int num_samples);

int main() {
    std::cout << "IQ Pipeline starting..." << std::endl;

    IQQueue<std::complex<float>> q(100);
    std::thread p(producer, std::ref(q), 10);
    std::thread c(consumer, std::ref(q), 10);
    p.join();
    c.join();

    return 0;
}
