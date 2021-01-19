#ifndef CPLUSPLUS_REDIS_DB_REDIS_DB
#define CPLUSPLUS_REDIS_DB_REDIS_DB

#include <array>
#include "base_strc/object.h"
#include <map>

namespace redis {

struct EvictionEntry {
    mstime_t idle;
    string_t key;
};

class RedisDb {
public:
    class RedisClient;
    using client_weak_ptr = std::weak_ptr<RedisClient>;
public:
   Robj* LookupKeyRead(const string_t& key);

   Robj* LookupKeyWrite(const string_t& key);

   bool lookup_key_read_or_reply(client_weak_ptr client_ptr, const string_t key, Robj* value, Robj reply);

   bool lookup_key_write_or_reply(client_weak_ptr client_ptr, const string_t key, Robj* value, Robj reply);

   void Add(const string_t& key, Robj val);

   void OverWrite(const string_t& key, Robj val);

   void SetKey(const string_t& key, Robj val);

   bool HasKey(const string_t& key);

   bool RandomKey(string_t* key);

   bool Del(const string_t& key);

private:
   Robj* LookupKey(const string_t& key);

   int ExpireIfNeeded(const string_t& key);

   mstime_t GetExpire(const string_t& key);


private:
    std::unordered_map<string_t, Robj> dict_;
    std::unordered_map<string_t, mstime_t> expires_;
    std::unordered_map<string_t, std::list<client_weak_ptr>> blocking_keys_;
    std::unordered_set<string_t> ready_keys_;
    std::unordered_map<string_t, std::list<client_weak_ptr>> watched_keys_;
    std::array<EvictionEntry,16> eviction_pool_;
    int32_t id_;
    int64_t avg_ttl_;
};


}//redis


#endif ///CPLUSPLUS_REDIS_DB_REDIS_DB
