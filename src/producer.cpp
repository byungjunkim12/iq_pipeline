#include <iostream>
#include <complex>
#include <thread>
#include "queue.h"

void producer(IQQueue<std::complex<float>>& queue, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        std::complex<float> sample(i * 1.0f, i * 0.5f);
        queue.push(sample);
        std::cout << "Produced: " << sample << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
