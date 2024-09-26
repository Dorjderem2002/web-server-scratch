#include "listensocket.hpp"
using namespace sea;
ListenSocket::ListenSocket(int domain, int service, int protocol, int port, u_long interface, int backlog) : BindSocket(domain, service, protocol, port, interface)
{
    m_backlog = backlog;
    init_listen();
    if (m_listen < 0)
    {
        std::cerr << "Failed to listen" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void ListenSocket::init_listen()
{
    m_listen = listen(get_socket(), m_backlog);
}
