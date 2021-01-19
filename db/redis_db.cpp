#include "db/redis_db.h"

#include <assert.h>

namespace redis {




Robj* RedisDb::LookupKey(const string_t& key) {
    if (dict_.end() != dict_.find(key)) {
        return &dict_[key];
    }

    return nullptr;
}

int RedisDb::ExpireIfNeeded(const string_t& key) {

}

mstime_t RedisDb::GetExpire(const string_t& key) {
    if (expires_.find(key) == expires_.end())
        return -1;

    assert(dict_.find(key) != dict_.end());

    return expires_[key];
}


bool RedisDb::HasKey(const string_t& key) {

    if (dict_.end() != dict_.find(key)) {
        return true;
    }

    return false;
}


}
