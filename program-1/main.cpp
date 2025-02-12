#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

#include "lib.h"
#include "recipient.h"

#include "dispatcher.h"

#include "client.h"

int main() {

    Client foo("127.0.0.1", 5252);


    foo.connect();

    for(;;) {
        foo.send("test");
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }



    return -1;
    Dispatcher boo;

    boo.start();


    for(;;) {
        std::cout << "main works" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }



    return 0;
}
