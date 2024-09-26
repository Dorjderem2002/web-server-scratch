#include <iostream>

#include "server/httpserver.hpp"

int main()
{
    sea::HTTPServer server = sea::HTTPServer(8080, 10);
    server.start();

    return 0;
}