#ifndef RECIPIENT_H
#define RECIPIENT_H

#include "lib.h"
#include "idispatcher.h"

class Recipient {
public:
    Recipient() = default;

    void attach(IDispatcher* observer) {m_observer = observer;}
    void detach() {m_observer = nullptr;}
    void notify();

    void input();

    bool isValid() const;

    void operator()();

private:
    std::string m_data = {};
    IDispatcher* m_observer = nullptr;
};

#endif // RECIPIENT_H
