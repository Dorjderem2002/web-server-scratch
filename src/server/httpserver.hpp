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

        bool m_silent = false;

        std::unordered_map<std::string, std::string> m_headers = std::unordered_map<std::string, std::string>{
            {"Server", "Dorj"},
            {"Content-Type", "text/html"},
        };
        std::unordered_map<int, std::string> m_status_code = std::unordered_map<int, std::string>{
            {200, "OK"},
            {404, "Not Found"},
        };

        std::string build_response_line(int status_code);
        std::string build_headers(std::unordered_map<std::string, std::string> *const extra_headers);
        std::string build_response(std::string body);
    };
}