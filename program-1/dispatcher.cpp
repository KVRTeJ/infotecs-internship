#include "dispatcher.h"

void Dispatcher::start() {
    Recipient foo;
    foo.attach(this);

    foo();

    // std::thread inp(foo);

    // inp.join();
}
