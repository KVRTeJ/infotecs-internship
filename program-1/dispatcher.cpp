#include "dispatcher.h"

#include <thread>

void Dispatcher::setClient(IClient* client) {
    if(!client) {
        return;
    }

    m_client = client;
}

void Dispatcher::sender() {

    for(;;) {
        std::unique_lock<std::mutex> lock(m_mutex);

        while(m_buffer.empty() && !m_client->connected()) {
            m_client->connect();
        }

        m_condition_variable.wait(lock, [this]{
            return !m_buffer.empty();
        });

        std::string data = m_buffer.pop();
        std::cout << data <<std::endl;

        std::string output = std::to_string(getSumNumbers(data));

        if(m_client) {
            while(!m_client->send(output));
        }
    }
}

void Dispatcher::start() {
    Recipient baseInputClass;
    baseInputClass.attach(this);

    std::thread input(baseInputClass);

    if(m_client) {
        m_client->connect();
    }

    std::thread output(&Dispatcher::sender, this);

    input.join();
    output.join();
}
