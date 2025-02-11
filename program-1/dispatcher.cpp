#include "dispatcher.h"

#include <thread>

void Dispatcher::start() {
    Recipient hostInputClass;
    hostInputClass.attach(this);

    std::thread input(hostInputClass);

    input.detach();
}
