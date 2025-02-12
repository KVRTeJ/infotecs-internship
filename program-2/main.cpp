#include <iostream>
#include <thread>
#include <chrono>

#include "lib.h"

#include "server.h"

int main() {

    Server boo(5252);

    boo.start();

    return 0;
}
