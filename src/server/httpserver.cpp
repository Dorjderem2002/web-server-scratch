#include "httpserver.hpp"
#include "httprequest.hpp"

sea::HTTPServer::HTTPServer(int port, int backlog) : TCPServer(port, backlog)
{
}

void sea::HTTPServer::start()
{
    if (!m_silent)
    {
        std::cout << "Starting server on port: " << get_socket().get_address().sin_port << std::endl;
    }
    while (true)
    {
        std::cout << "====== WAITING ======" << std::endl;
        int socket_arg = accepter();

        // std::thread pt([this, socket_arg]
        //                { handle_task(socket_arg); });
        // pt.join();
        handle_task(socket_arg);
        close(socket_arg);
    }
}

int sea::HTTPServer::accepter()
{
    struct sockaddr_in addr = get_socket().get_address();
    int addrlen = sizeof(addr);
    int res_socket = accept(get_socket().get_socket(), (struct sockaddr *)&addr, (socklen_t *)&addrlen);
    if (res_socket < 0)
    {
        std::cerr << "Can not accept" << std::endl;
        exit(EXIT_FAILURE);
    }
    return res_socket;
}

void sea::HTTPServer::handler(int client_socket)
{
    read(client_socket, m_buffer, sizeof(m_buffer));
    std::cout << m_buffer << std::endl;
    sea::HTTPRequest req(m_buffer);

    std::cout << req.uri << std::endl;
    if (req.method == "GET")
    {
    }
    else
    {
    }
}

void sea::HTTPServer::responder(int client_socket)
{
    std::string response_line = build_response_line(200);
    std::string headers = build_headers(nullptr);
    std::string blank_line = "\r\n";
    std::string response_body = "<html><h1>RESPECT<h1></html>";
    std::string final_response = response_line + headers + blank_line + response_body;
    write(client_socket, final_response.c_str(), final_response.size());
}

void sea::HTTPServer::handle_task(int client_sock)
{
    handler(client_sock);
    responder(client_sock);
}

std::string sea::HTTPServer::build_response(std::string body)
{
    std::string response;

    return response;
}

std::string sea::HTTPServer::build_response_line(int status_code)
{
    return "HTTP/1.1 " + std::to_string(status_code) + " " + m_status_code[status_code] + "\r\n";
}

std::string sea::HTTPServer::build_headers(std::unordered_map<std::string, std::string> *const extra_headers = nullptr)
{
    std::unordered_map<std::string, std::string> response_headers = m_headers;
    if (extra_headers != nullptr)
    {
        for (auto it : *extra_headers)
        {
            response_headers[it.first] = it.second;
        }
    }

    std::string final_str_header;
    const std::string new_line = "\r\n";
    for (auto it : response_headers)
    {
        final_str_header += it.first + ": " + it.second + new_line;
    }

    return final_str_header;
}