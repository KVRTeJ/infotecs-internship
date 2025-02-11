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
        m_buffer.add(message);
        lock.unlock();

        m_condition_variable.notify_one();
    }

    void sender(); //TODO:implementme

    void start();

private:
    std::mutex m_mutex;
    std::condition_variable m_condition_variable;

    Container<std::string> m_buffer = {};
};

#endif // DISPATCHER_H
