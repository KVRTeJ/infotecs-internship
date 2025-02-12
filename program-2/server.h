#ifndef SERVER_H
#define SERVER_H

#include<list>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <unistd.h>

#include "lib.h"

class Server {
    using Socket = int;

    enum class Status : bool {
        OFF = false,
        ON = true
    };

    struct Client {
        sockaddr_in address;
        Socket socket;

        Server::Status status = Status::OFF;
    };

public:
    Server(int port) : m_port(port)
    {}

    Status start() {
        socklen_t addressSize = sizeof(m_address);

        m_address.sin_addr.s_addr = INADDR_ANY;
        m_address.sin_port = htons(m_port);
        m_address.sin_family = AF_INET;

        m_socket = socket(AF_INET, SOCK_STREAM, 0);

        bind(m_socket, (struct sockaddr*)&m_address, sizeof(m_address));

        listen(m_socket, SOMAXCONN);

        m_status = Status::ON;

        m_client.socket = accept(m_socket, (struct sockaddr*)&m_client.address, &addressSize);

    }

private:
    Status m_status = Status::OFF;

    sockaddr_in m_address;
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
