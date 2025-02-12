#include <iostream>
#include <thread>
#include <chrono>

#include "lib.h"

#include "server.h"

int main() {

    Server boo(5252, [](std::string message) {
        std::cout << "handler checked msg - " << message << std::endl;
    });

    boo.start();

    return -1;
}
