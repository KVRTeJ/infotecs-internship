#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

#include "lib.h"
#include "container.h"

template<typename Type >
void checkCont(Container<Type>& data) {

    for(;;) {
        auto foo = data.pop();
        std::cout << std::this_thread::get_id() << "\t - \t" << foo << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

void checkCont2(Container<int>& data) {

    for(;;) {
        int foo = rand() % 15;
        data.add(foo);
        std::cout << std::this_thread::get_id() << "\t - \t" << foo << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {

    Container<int> boo;

    boo.add(2);

    // std::thread adder([&]() {
    //     checkCont2(boo);
    // });


    std::thread popper([&]() {
        checkCont(boo);
    });

    // std::cout << "start" << std::endl;
    // for(;;) {
    //     //std::cout << "main works" << std::endl;
    //     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // }

    // adder.join();
    popper.join();
    return 0;
}
