#include "replace.hpp"

std::string str_replace(const std::string &str, const std::string &s1, const std::string &s2)
{
    if (s1.empty())
        return str;
    std::string result;
    size_t pos = 0;
    size_t found;
    while ((found = str.find(s1, pos)) != std::string::npos) {
        result.append(str, pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result.append(str, pos, str.length() - pos);
    return result;
}