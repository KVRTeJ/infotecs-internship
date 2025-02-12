#include "server.h"

void Server::setPort(const int port) {
    if(port <= 0 || port == m_port) {
        return;
    }

    m_port = port;
    start();
}

Server::Status Server::start() {

    m_address.sin_addr.s_addr = INADDR_ANY;
    m_address.sin_port = htons(m_port);
    m_address.sin_family = AF_INET;

    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(m_socket == -1) {
        //TODO:Message
        return Status::OFF;
    }

    bool flag = true;
    setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));

    if(bind(m_socket, reinterpret_cast<const sockaddr*>(&m_address), sizeof(m_address)) < 0) {
        //TODO:Message
        return Status::OFF;
    }


    if(listen(m_socket, SOMAXCONN) < 0) {
        //TODO:Message
        return Status::OFF;
    }

    m_status = Status::ON;
    std::cout << "server started" << std::endl;

    connectClient();

    dataLoop();
}

void Server::dataLoop() {
    char buffer[BUFFER_SIZE];

    for(;;) {
        int readed = read(m_client.socket, buffer, BUFFER_SIZE);
        if(readed <= 0) {
            std::cout << "Data read error. Try ro reconnect. . ." << std::endl;
            reconnectClient();
            continue;
        }

        std::cout << "dataLoop 1" << std::endl;

        m_handler(buffer);

        std::cout << "dataLoop 2" << std::endl;

        memset(buffer, 0, BUFFER_SIZE);

        std::cout << "dataLoop 3" << std::endl;
    }
}

bool Server::connectClient() {
    if(m_client.status == Status::ON) {
        return true;
    }

    socklen_t addressSize = sizeof(m_client.address);
    m_client.socket = accept(m_socket, (struct sockaddr*)&m_client.address, &addressSize);
    return (m_client.socket >= 0);
}

void Server::disconnectClient() {
    if(m_client.status == Status::OFF) {
        return;
    }

    m_client.status = Status::OFF;

    shutdown(m_client.socket, 0);
    close(m_client.socket);
}

bool Server::reconnectClient() {
    disconnectClient();
    return connectClient();
}


void Server::stop() {
    disconnectClient();

    m_status = Status::OFF;
    shutdown(m_socket, 0);
    close(m_socket);
}
