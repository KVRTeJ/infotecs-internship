#ifndef IDISPATCHER_H
#define IDISPATCHER_H

#include <iostream>
#include <string>

class IDispatcher {
public:
    virtual ~IDispatcher() = default;
    virtual void update(const std::string& message) = 0;
};

#endif // IDISPATCHER_H
