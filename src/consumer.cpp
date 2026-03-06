#include <iostream>
#include <complex>
#include <thread>
#include "queue.h"

void consumer(IQQueue<std::complex<float>>& queue) {
    std::complex<float> item;
    while (queue.pop(item)) {
        std::cout << "consumed: " << item << "\n";
    }
}
