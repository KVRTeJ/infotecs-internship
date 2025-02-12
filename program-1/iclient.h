#ifndef ICLIENT_H
#define ICLIENT_H

#include <iostream>

class IClient {
public:
    virtual ~IClient() = default;

    virtual void setPort(const int port) = 0;
    virtual void setIp(const std::string& ip) = 0;

    virtual int getPort() const = 0;
    virtual std::string getIp() const = 0;

    virtual bool connect() = 0;
    virtual void disconnect() = 0;

    virtual bool send(const std::string& message) = 0;
};

#endif // ICLIENT_H
