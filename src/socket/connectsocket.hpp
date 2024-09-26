#pragma once
#include "socket.hpp"

namespace sea
{
    class ConnectSocket : public Socket
    {
    public:
        ConnectSocket(int domain, int service, int protocol, int port, u_long interface);
        int connect_network(int sock, struct sockaddr_in address) override;

    private:
    };
}
