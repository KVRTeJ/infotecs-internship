#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <list>

template <typename Type>
class Container {
public:
    Container() = default;

    void add(const Type& value) {
        m_data.push_back(value);
    }

    Type pop() {
        if(m_data.empty()) {
            return {};
        }

        Type result = m_data.front();
        m_data.pop_front();

        return result;
    }

    Type get() const {
        return m_data.front();;
    }

    bool empty() const {
        return m_data.empty();
    }

private:
    std::list<Type> m_data = {};
};

#endif // CONTAINER_H
