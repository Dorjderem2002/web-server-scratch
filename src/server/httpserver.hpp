#pragma once

#include "tcpserver.hpp"
#include <unistd.h>
#include <unordered_map>
#include <thread>

namespace sea
{
    class HTTPServer : public TCPServer
    {
    public:
        HTTPServer(int port, int backlog);
        void start() override;

    private:
        int accepter() override;
        void handler(int client_socket) override;
        void responder(int client_socket) override;

        void handle_task(int client_sock);

        char m_buffer[30000] = {0};

        bool m_silent = false;

        std::unordered_map<std::string, std::string> m_headers = std::unordered_map<std::string, std::string>{
            {"Server", "Dorj"},
            {"Content-Type", "text/html"},
        };
        std::unordered_map<int, std::string> m_status_code = std::unordered_map<int, std::string>{
            {200, "OK"},
            {404, "Not Found"},
            {501, "Not Implemented"},
        };

        std::string build_response_line(int status_code);
        std::string build_headers(std::unordered_map<std::string, std::string> *const extra_headers);
        std::string build_response(std::string body);
    };
}