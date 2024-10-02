#include "httprequest.hpp"
#include "../utils/my_utils.hpp"

sea::HTTPRequest::HTTPRequest(const char data[30000])
{
    parse(data);
}

void sea::HTTPRequest::parse(const char data[30000])
{
    std::vector<std::string> lines(1, "");
    int n = 300000;
    for (int i = 0; i < n; i++)
    {
        if (data[i] == 0)
            break;
        if (data[i] == '\n')
        {
            lines.push_back("");
        }
        else
        {
            lines.back().push_back(data[i]);
        }
    }
    // line[0] contains METHOD URI HTTP_V LINE_BREAK
    std::vector<std::string> words = sea::split(lines[0]);
    method = words[0];
    if (words.size() > 1)
        uri = words[1];
    if (words.size() > 2)
        http_version = words[2];
}
