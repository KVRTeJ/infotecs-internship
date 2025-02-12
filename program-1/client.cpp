#include "client.h"

void Client::setPort(const int port) {
    if(port <= 0 || port == m_port) {
        return;
    }

    isConnected = false;
    m_port = port;
}

void Client::setIp(const std::string& ip) {
    isConnected = false;
    m_ip = ip;
}

bool Client::connect() {
    if(isConnected) {
        disconnect();
    }

    m_address.sin_port = htons(m_port);
    m_address.sin_family = AF_INET;
    inet_pton(AF_INET, m_ip.c_str(), &(m_address.sin_addr));

    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(m_socket == -1) {
        std::cerr << "Error creating socket." << std::endl;
        return false;
    }

    if((::connect(m_socket, reinterpret_cast<const sockaddr*>(&m_address), sizeof(m_address))) < 0) {
        std::cerr << "Server connection error." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        return false;
    }

    std::cout << "Client connected to server." << std::endl;

    isConnected = true;
    return true;
}

void Client::disconnect() {
    isConnected = false;

    shutdown(m_socket, 0);
    close(m_socket);
    m_socket = -1;
}

bool Client::reconnect() {
    disconnect();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return connect();
}

bool Client::send(const std::string& message) {
    if(!isConnected) {
        connect();
    }

    int size = ::send(m_socket, message.c_str(), message.length(), MSG_NOSIGNAL);
    if(size <= 0) {
        std::cerr << "Data send error. Try to reconnect. . ." << std::endl;
        reconnect();
        return false;
    }

    return true;
}
