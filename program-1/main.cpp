#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

#include "lib.h"
#include "recipient.h"

#include "dispatcher.h"

int main() {

    Dispatcher boo;

    boo.start();


    for(;;) {
        std::cout << "main works" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }



    return 0;
}
