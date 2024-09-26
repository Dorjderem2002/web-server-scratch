#include "tcpserver.hpp"
using namespace sea;

TCPServer::TCPServer(int port, int backlog)
{
    m_socket = std::make_unique<ListenSocket>(AF_INET, SOCK_STREAM, 0, port, INADDR_ANY, backlog);
}

ListenSocket &TCPServer::get_socket() const
{
    return *m_socket;
}
