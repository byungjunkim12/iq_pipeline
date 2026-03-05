#include <iostream>
#include <complex>
#include <thread>
#include "queue.h"

void consumer(IQQueue<std::complex<float>>& queue, int num_samples) {
    int count = 0;
    while (count < num_samples) {
        if (!queue.empty()){
            std::complex<float> sample = queue.pop();
            count++;
            std::cout << "Consumed: " << sample << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    }
}
