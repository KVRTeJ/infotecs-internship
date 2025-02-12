#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>

#include <thread>
#include <chrono>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#include "iclient.h"

class Client : public IClient {
    using Socket = int;
public:
    Client(std::string ip, int port, bool errorMessagesVision = false) : m_ip(ip), m_port(port), showErrorMessages(errorMessagesVision) {}
    ~Client() override = default;

    void setPort(const int port) override;
    void setIp(const std::string& ip) override;
    void setErrorMessagesVision(const bool value) {showErrorMessages = value;}

    int getPort() const override {return m_port;}
    std::string getIp() const override {return m_ip;}
    bool getErrorMessagesVision() const {return showErrorMessages;}

    bool connect() override;
    void disconnect() override;
    bool reconnect();

    bool send(const std::string& message) override;

private:
    bool showErrorMessages = false;
    bool isConnected = false;

    struct sockaddr_in m_address;
    Socket m_socket = -1;

    int m_port = -1;
    std::string m_ip = "";
};

#endif // CLIENT_H
