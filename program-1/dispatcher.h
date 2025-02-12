#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "container.h"
#include "idispatcher.h"
#include "recipient.h"
#include "iclient.h"

class Dispatcher : public IDispatcher {
public:
    Dispatcher(IClient* client = nullptr) : m_client(client) {}
    ~Dispatcher() override = default;

    void update(const std::string& message) override {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_buffer.add(message);
        lock.unlock();

        m_condition_variable.notify_one();
    }

    void setClient(IClient* client);
    IClient* getClient() const {return m_client;}

    void sender();

    void start();

private:
    std::mutex m_mutex;
    std::condition_variable m_condition_variable;

    Container<std::string> m_buffer = {};

    IClient* m_client = nullptr;
};

#endif // DISPATCHER_H
