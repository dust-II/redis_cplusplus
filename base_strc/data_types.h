#ifndef CPLUSPLUS_REDIS_BASE_STRC_DATA_TYPES
#define CPLUSPLUS_REDIS_BASE_STRC_DATA_TYPES

#include <string>
#include <list>
#include <unordered_set>
#include <unordered_map>

namespace redis {

/* redis object type */
using string_t = std::string;
using list_t   = std::list<string_t>;
using set_t    = std::unordered_set<string_t>;
using hash_t   = std::unordered_map<string_t, string_t>;


using mstime_t = long long; //millisecond time type.

}//redis


#endif ///CPLUSPLUS_REDIS_BASE_STRC_DATA_TYPES
