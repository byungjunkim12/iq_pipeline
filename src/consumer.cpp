#include <iostream>
#include <mutex>
#include "queue.h"

void consumer(IQQueue<std::complex<float>>& queue, int num_samples){
    int count = 0;
    std::complex<float> item;
    while (queue.pop(item)){
        std::cout << "consumed: " << item << "\n";
    }
}
