#ifndef CPLUSPLUS_REDIS_SERVER_SERVER
#define CPLUSPLUS_REDIS_SERVER_SERVER

#include <array>
#include "base_strc/object.h"

namespace redis {


class RedisServer {
public:

    RedisServer(const RedisServer&)            = delete;
    RedisServer(RedisServer&&)                 = delete;
    RedisServer& operator=(const RedisServer&) = delete;
    RedisServer& operator=(RedisServer&&)      = delete;
    ~RedisServer()                             = default;
    static std::shared_ptr<RedisServer> instance();
private:
    RedisServer() = default;
    static std::shared_ptr<RedisServer> instance_;
};


}//redis


#endif ///CPLUSPLUS_REDIS_SERVER_SERVER
