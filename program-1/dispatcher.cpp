#include "dispatcher.h"

#include <thread>

void Dispatcher::sender() {

    for(;;) {
        std::unique_lock<std::mutex> lock(m_mutex);

        std::cout << "sender wait" << std::endl;

        m_condition_variable.wait(lock, [this]{
            //std::cout << "until wait" << (!m_buffer.empty() ? "\ttrue\t" : "\tfalse\t") << std::endl;
            return !m_buffer.empty();
            // return hasData;
        });

        std::cout << "sender started" << std::endl;
        std::cout << m_buffer.pop() << " processed.\n" << std::endl;
    }
}

void Dispatcher::start() {
    Recipient baseInputClass;
    baseInputClass.attach(this);

    std::thread input(baseInputClass);
    std::thread output(&Dispatcher::sender, this);

    input.join();
    output.join();
}
