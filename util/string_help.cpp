
#include "util/string_help.h"
#include <string.h>

namespace redis{

namespace util {

static uint32_t BKDR_hash(const char* str)
{
    if (nullptr == str)
    {
        return 0;
    }

    const uint32_t seed = 131;//31  131 1313 13131131313 etc//
    uint32_t hash = 0;

    while(*str)
    {
        hash = (hash * seed) + (*str);
        str++;
    }

    return  hash & 0x7FFFFFFF;
}

uint32_t StrHash_BKDR::operator()(const string_t& str) const
{
    if (str.empty())
    {
        return 0;
    }

    return BKDR_hash(str.c_str());
}

/**
* Split string on delim.
*
* @param The string to be split.
* @param The separator characters.
* @returns Vector with the parts of the string split up. Empty strings will not remove from result.
*/
std::vector<std::string> str_split(const std::string& src_str, const char* delim)
{
    std::vector<std::string> tokens;
    if (src_str.empty() || nullptr == delim)
        return tokens;

    size_t delim_len = strlen(delim);
    std::string::size_type pos = 0;
    while(pos < src_str.size())
    {
        std::string::size_type next_pos = src_str.find(delim, pos);
        if(std::string::npos == next_pos)
            next_pos = src_str.size();

        if(pos < next_pos)
            tokens.push_back(src_str.substr(pos, next_pos - pos));

        if(pos == next_pos)
            tokens.push_back("");

        pos = next_pos + delim_len;
    }

    return tokens;
}

bool start_with(const std::string& src_str, const std::string& head_str)
{
    if (src_str.size() < head_str.size())
        return false;

    return (0 == src_str.compare(0, head_str.size(), head_str)) ? true : false;
}

void trim_left(std::string & str)
{
     str.erase(0,str.find_first_not_of(" "));
}

void trim_right(std::string & str)
{
     str.erase(str.find_last_not_of(" ") + 1);

     size_t n = str.find_last_not_of(" \r\n\t");
     if( n != std::string::npos )
     {
         str.erase( n + 1 , str.size() - n );
     }
}

}

}
