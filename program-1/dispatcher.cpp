#include "dispatcher.h"

#include <thread>

void Dispatcher::sender() {
    std::unique_lock<std::mutex> lock(m_mutex);

    std::cout << "sender wait" << std::endl;
    bool hasData = !buffer.empty();
    m_condition_variable.wait(lock, [&hasData]{
        std::cout << "until wait" << (hasData ? "\ttrue\t" : "\tfalse\t") << std::endl;
        return hasData;
    });

    std::cout << "sender started" << std::endl;

}

void Dispatcher::start() {
    Recipient baseInputClass;
    baseInputClass.attach(this);

    std::thread input(baseInputClass);
    std::thread output(&Dispatcher::sender, this);

    input.join();
    output.join();
}
