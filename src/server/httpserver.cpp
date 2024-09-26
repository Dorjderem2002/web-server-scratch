#include "httpserver.hpp"

sea::HTTPServer::HTTPServer(int port, int backlog) : TCPServer(port, backlog)
{
}

void sea::HTTPServer::start()
{
    if (!silent)
    {
        std::cout << "Starting server on port: " << get_socket().get_address().sin_port << std::endl;
    }
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
    std::string headers = "Server: Dorj's server\r\nContent-Type: text/html\r\n";
    std::string response_line = "HTTP/1.1 200 OK\r\n";
    std::string blank_line = "\r\n";
    std::string response_body = "<html><h1>RESPECT<h1></html>";

    std::string final_response = response_line + headers + blank_line + response_body;

    write(m_new_socket, final_response.c_str(), final_response.size());
    close(m_new_socket);
}
