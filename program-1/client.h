#ifndef CLIENT_H
#define CLIENT_H


#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>


class Client {
    using Socket = int;
public:
    Client(int port) : m_port(port) {}

    void connectTo() {
        socklen_t addressSize = sizeof(m_address);

        m_address.sin_port = htons(m_port);
        m_address.sin_family = AF_INET;
        inet_pton(AF_INET, "127.0.0.1", &(m_address.sin_addr));

        m_socket = socket(AF_INET, SOCK_STREAM, 0);

        if(connect(m_socket, (struct sockaddr*)&m_address, sizeof(m_address)) < 0) {
            std::cout << "err connect to server" << std::endl;
        }

        const char* message = "Hello, Server!";

        send(m_socket, message, strlen(message), 0);

    }



private:
    struct sockaddr_in m_address;
    Socket m_socket = -1;
    int m_port = -1;
};

#endif // CLIENT_H
