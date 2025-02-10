#ifndef RECIPIENT_H
#define RECIPIENT_H

#include <thread>
#include <mutex>
#include <condition_variable>

#include "lib.h"

class Recipient {
public:
    explicit Recipient(std::condition_variable cv)
        :m_cv(cv)
    {}

    bool isValid() const;

    bool start();

    Recipient(const Recipient& other) = delete;
    Recipient& operator = (const Recipient& other) = delete;

private:
    std::string m_data = {};
    std::condition_variable m_cv = {};
};

#endif // RECIPIENT_H
