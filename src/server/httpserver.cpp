#include "httpserver.hpp"

sea::HTTPServer::HTTPServer(int domain, int backlog) : TCPServer(domain, backlog)
{
}

void sea::HTTPServer::start()
{
    while (true)
    {
        std::cout << "====== WAITING ======" << std::endl;
        accepter();
        handler();
        responder();
    }
}

void sea::HTTPServer::accepter()
{
    struct sockaddr_in addr = get_socket().get_address();
    int addrlen = sizeof(addr);
    m_new_socket = accept(get_socket().get_socket(), (struct sockaddr *)&addr, (socklen_t *)&addrlen);
    if (m_new_socket < 0)
    {
        std::cerr << "Can not accept" << std::endl;
        exit(EXIT_FAILURE);
    }
    read(m_new_socket, m_buffer, sizeof(m_buffer));
}

void sea::HTTPServer::handler()
{
    std::cout << m_buffer << std::endl;
}

void sea::HTTPServer::responder()
{
    std::string response_line = "HTTP/1.1 200 OK\r\n";
    std::string blank_line = "\r\n";
    std::string response_body = "Request received!";

    std::string final_response = response_line + blank_line + response_body;

    write(m_new_socket, final_response.c_str(), final_response.size());
    close(m_new_socket);
}
