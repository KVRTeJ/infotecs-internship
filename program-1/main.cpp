#include "dispatcher.h"

#include "client.h"

int main() {

    Client client("127.0.0.1", 5252);

    Dispatcher main(&client);

    main.start();

    return 0;
}
