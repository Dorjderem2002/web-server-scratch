#pragma once

#include "bindsocket.hpp"

namespace sea
{
    class ListenSocket : public BindSocket
    {
    public:
        ListenSocket(int domain, int service, int protocol, int port, u_long interface, int backlog);
        void init_listen();

    private:
        int m_backlog;
        int m_listen;
    };
}
