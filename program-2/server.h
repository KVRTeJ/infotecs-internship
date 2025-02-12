#ifndef SERVER_H
#define SERVER_H

#include<list>
#include <functional>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <cstring>
#include <string.h>

#include "lib.h"

class Server {
    using Socket = int;

    enum class Status : bool {
        OFF = false,
        ON = true
    };

    struct Client {
        struct sockaddr_in address;
        Socket socket;

        Server::Status status = Status::OFF;
    };

public:
    Server(int port, std::function<void(std::string message)> handler = nullptr) : m_port(port), m_handler(handler)
    {}

    void setPort(const int port);
    int getPort() const {return m_port;}
    Status getStatus() const {return m_status;}

    Status start();
    void dataLoop();

    bool connectClient();
    void disconnectClient();
    bool reconnectClient();

    void stop();

    static const int BUFFER_SIZE = 128;
private:
    std::function<void(std::string message)> m_handler;
    Status m_status = Status::OFF;

    struct sockaddr_in m_address;
    Socket m_socket = -1;
    int m_port = -1;

    Client m_client;

};

// struct Server::Client {
//     sockaddr_in address;
//     Socket socket;

//     Server::Status status = Status::OFF;
// };

#endif // SERVER_H
