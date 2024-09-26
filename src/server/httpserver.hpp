#pragma once

#include "tcpserver.hpp"
#include <unistd.h>
#include <unordered_map>

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
        char m_buffer[30000] = {0};
        int m_new_socket;

        bool silent = false;

        std::unordered_map<std::string, std::string> headers = std::unordered_map<std::string, std::string>{
            {"Server", "Dorj"},
            {"Content-Type", "text/html"},
        };
        std::unordered_map<int, std::string> status_code = std::unordered_map<int, std::string>{
            {200, "OK"},
            {404, "Not Found"},
        };
    };
}