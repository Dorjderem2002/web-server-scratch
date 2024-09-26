#include <iostream>

#include "server/httpserver.hpp"

int main(int argc, char *argv[])
{
    int port = 8080, backlog = 10;

    if (argc >= 2)
        port = std::stoi(argv[1]);
    if (argc == 3)
        backlog = std::stoi(argv[2]);

    sea::HTTPServer server = sea::HTTPServer(port, backlog);
    server.start();

    return 0;
}