#include "connectsocket.hpp"

using namespace sea;

ConnectSocket::ConnectSocket(int domain, int service, int protocol, int port, u_long interface) : Socket(domain, service, protocol, port, interface)
{
    // establish connection
    int connection = connect_network(get_socket(), get_address());

    if (connection < 0)
    {
        std::cerr << "Failed to establish connection" << std::endl;
        exit(EXIT_FAILURE);
    }

    set_connection(connection);
}

int ConnectSocket::connect_network(int sock, sockaddr_in address)
{
    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}
