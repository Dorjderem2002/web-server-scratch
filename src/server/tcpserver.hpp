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

        virtual int accepter() = 0;
        virtual void handler(int client_socket) = 0;
        virtual void responder(int client_socket) = 0;
    };
}
