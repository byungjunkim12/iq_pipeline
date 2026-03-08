#include <iostream>
#include <thread>
#include <complex>
#include "queue.h"

void consumer(IQQueue<std::complex<float>>& queue, int num_samples) {
    std::complex<float> item;
    while (queue.pop(item)) {
        std::cout << "consumed: " << item << "\n";
    }
}

