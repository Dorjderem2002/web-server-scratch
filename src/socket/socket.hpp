#pragma once

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

namespace sea
{
    class Socket
    {
    public:
        Socket(int domain, int service, int protocol, int port, u_long interface);
        virtual int connect_network(int sock, struct sockaddr_in address) = 0;

        struct sockaddr_in get_address();
        int get_socket();

        void set_connection(int connection);

    private:
        struct sockaddr_in m_address;
        int m_sock;
        int m_connection;
    };
}
