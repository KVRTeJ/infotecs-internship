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

    return 0;
}
