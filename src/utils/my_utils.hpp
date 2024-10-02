#pragma once

#include <string>
#include <vector>
#include <iostream>

namespace sea
{
    std::vector<std::string> split(const std::string &line)
    {
        std::vector<std::string> res(1, "");
        for (const char &i : line)
        {
            if (i == ' ')
            {
                res.push_back("");
            }
            else
            {
                res.back().push_back(i);
            }
        }
        return res;
    }
}
