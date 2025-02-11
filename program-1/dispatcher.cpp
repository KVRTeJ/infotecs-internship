#include "dispatcher.h"

#include <thread>

void Dispatcher::sender() {

    for(;;) {
        std::unique_lock<std::mutex> lock(m_mutex);

        m_condition_variable.wait(lock, [this]{
            return !m_buffer.empty();
        });

        std::string data = m_buffer.pop();
        std::cout << data <<std::endl;

        std::string output = std::to_string(getSumNumbers(data));
        std::cout << output << std::endl; //TODO: remove

    }
}

void Dispatcher::start() {
    Recipient baseInputClass;
    baseInputClass.attach(this);

    std::thread input(baseInputClass);

    //TODO: start server

    std::thread output(&Dispatcher::sender, this);

    input.join();
    output.join();
}
