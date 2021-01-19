#ifndef CPLUSPLUS_REDIS_UTIL_STRING_H
#define CPLUSPLUS_REDIS_UTIL_STRING_H

#include <string>
#include <vector>
#include "base_strc/data_types.h"

namespace redis{

namespace util {

template<typename T>
inline T str_to_numeric(const std::string& str)
{
    return std::stoi(str);
}

template<>
inline long str_to_numeric<long>(const std::string& str)
{
    return std::stol(str);
}

template<>
inline unsigned long str_to_numeric<unsigned long>(const std::string& str)
{
    return std::stoul(str);
}

template<>
inline long long str_to_numeric<long long>(const std::string& str)
{
    return std::stoull(str);
}

template<>
inline float str_to_numeric<float>(const std::string& str)
{
    return std::stof(str);
}

template<>
inline double str_to_numeric<double>(const std::string& str)
{
    return std::stod(str);
}

template<>
inline long double str_to_numeric<long double>(const std::string& str)
{
    return std::stold(str);
}

std::vector<std::string> str_split(const std::string& src_str, const char* delim);

bool start_with(const std::string& src_str, const std::string& head_str);

void trim_left(std::string & str);

void trim_right(std::string & str);

class StrHash_BKDR
{
public:
    uint32_t operator()(const string_t& str) const;
};

}//util

}//redis


#endif // CPLUSPLUS_REDIS_UTIL_STRING_H
