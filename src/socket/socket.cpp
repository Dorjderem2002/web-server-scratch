#include "socket.hpp"

using namespace sea;

Socket::Socket(int domain, int service, int protocol, int port, u_long interface)
{
    // address structure
    m_address.sin_family = domain;
    m_address.sin_port = htons(port);
    m_address.sin_addr.s_addr = htonl(interface);

    // establish socket
    m_sock = socket(domain, service, protocol);

    if (m_sock < 0)
    {
        std::cerr << "Failed to establish socket" << std::endl;
        exit(EXIT_FAILURE);
    }
}

struct sockaddr_in Socket::get_address()
{
    return m_address;
}

int Socket::get_socket()
{
    return m_sock;
}

void Socket::set_connection(int connection)
{
    m_connection = connection;
}
