#pragma once

#include "../socket/listensocket.hpp"
#include <memory>

namespace sea
{
    class TCPServer
    {
    public:
        TCPServer(int port, int backlog);
        virtual void start() = 0;

        ListenSocket &get_socket() const;

    private:
        std::unique_ptr<ListenSocket> m_socket;

        virtual void accepter() = 0;
        virtual void handler() = 0;
        virtual void responder() = 0;
    };
}
