#include "server/server.h"

#include <assert.h>

namespace redis {


std::shared_ptr<RedisServer> RedisServer::instance_(nullptr);

std::shared_ptr<RedisServer> RedisServer::instance() {
    if (!instance_) {
        instance_ = std::shared_ptr<RedisServer>(new RedisServer);
    }

    return instance_;
}




}
