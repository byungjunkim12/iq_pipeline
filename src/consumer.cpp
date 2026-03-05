#include <iostream>
#include <mutex>
#include "queue.h"

void consumer(IQQueue<std::complex<float>>& queue, int num_samples){
    int count = 0;
    while (count < num_samples){
        std::complex<float> item = queue.pop();
        if (item == std::complex<float>{0, 0} && queue.is_done()) break;
        std::cout << "consumed: " << item << "\n";
        count++;
    }
}
