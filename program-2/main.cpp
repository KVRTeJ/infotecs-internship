#include "lib.h"

#include "server.h"

int main() {

    Server server(5252, [](std::string message) {
        std::cout << (analyse(message) ? "The data was accepted" : "Error: The data was not accepted") << std::endl;
    });

    server.start();

    return -1;
}
