#include "recipient.h"

void Recipient::notify() {
    if(!m_observer) {
        return;
    }

    m_observer->update(m_data);
}

void Recipient::input() {
    std::getline(std::cin, m_data);
}

bool Recipient::isValid() const {
    if(m_data.length() > 64 || m_data.empty()) {
        return false;
    }

    for(char i: m_data) {
        if((i < '0') || (i > '9')) {
            return false;
        }
    }

    return true;
}

void Recipient::operator()() {
    for(;;) {
        input();

        if(isValid()) {
            sortAndReplace(m_data);
            notify();
        }
    }
}
