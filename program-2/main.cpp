#include <iostream>
#include <thread>
#include <chrono>

#include "lib.h"

int main() {

    for(;;) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "program-2" << std::endl;
    }

    return 0;
}
