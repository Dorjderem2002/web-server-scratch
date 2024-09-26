#pragma once

#include "tcpserver.hpp"
#include <unistd.h>

namespace sea
{
    class HTTPServer : public TCPServer
    {
    public:
        HTTPServer(int port, int backlog);
        void start() override;

    private:
        void accepter() override;
        void handler() override;
        void responder() override;
        char m_buffer[3000] = {0};
        int m_new_socket;
    };
}