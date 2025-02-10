#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <list>
#include <mutex>
#include <thread>
#include <chrono>

template <typename Type>
class Container {
public:
    void add(const Type& value) {
        std::lock_guard<std::mutex> lock(m_mutex);

        m_data.push_back(value);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    Type pop() {
        if(m_data.empty()) {
            return {};
        }

        std::lock_guard<std::mutex> lock(m_mutex);

        Type result = m_data.front();
        m_data.pop_front();

        return result;
    }

    Type get() const {
        return m_data.front();;
    }
private:
    std::list<Type> m_data = {};
    std::mutex m_mutex;
};

#endif // CONTAINER_H
