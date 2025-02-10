#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "container.h"
#include "idispatcher.h"
#include "recipient.h"

class Dispatcher : public IDispatcher {
public:
    Dispatcher() = default;
    virtual ~Dispatcher() = default;
    void update(const std::string& message) override {
        std::unique_lock<std::mutex> lock(m_mutex);
        buffer.add(message);
        std::cout << buffer.pop() << std::endl;
        lock.unlock();
    }

    // void sender();

    void start();

private:
    std::mutex m_mutex;
    std::condition_variable m_condition_variable;

    Recipient m_recipient = {};
    Container<std::string> buffer = {};
};

#endif // DISPATCHER_H
