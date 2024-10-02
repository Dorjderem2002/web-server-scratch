#pragma once

#include <string>
#include <vector>
#include <iostream>

namespace sea
{
    class HTTPRequest
    {
    public:
        HTTPRequest(const char data[30000]);
        std::string method = "";
        std::string uri = "";
        std::string http_version = "1.1";
    private:
        void parse(const char data[30000]);
    };
}
