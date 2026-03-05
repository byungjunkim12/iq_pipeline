#include <iostream>
#include "queue.h"

int main() {
    std::cout << "IQ Pipeline starting..." << std::endl;

    IQQueue<float> q(10);
    q.push(1.0f);
    q.push(2.0f);
    std::cout << q.pop() << '\n';

    //IQQueue<float> q2 = q;

    return 0;
}
