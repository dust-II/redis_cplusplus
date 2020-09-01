#ifndef CPLUSPLUS_REDIS_BASE_STRC_OBJECT
#define CPLUSPLUS_REDIS_BASE_STRC_OBJECT

#include <stdint.h>
#include <memory>
#include <string>
#include <list>
#include <unordered_set>
#include <unordered_map>

namespace redis_cpp {

namespace base_strc {

/* The actual Redis Object */
/*
 * Redis 对象
 */

static constexpr uint8_t  K_REDIS_LRU_BITS = 24;
static constexpr uint32_t k_REDIS_LRU_CLOCK_MAX ((1<<K_REDIS_LRU_BITS)-1); /* Max value of obj->lru */
static constexpr uint32_t K_REDIS_LRU_CLOCK_RESOLUTION = 1000; /* LRU clock resolution in ms */

using string_t = std::string;
using list_t   = std::list<string_t>;
using set_t    = std::unordered_set<string_t>;
using hash_t   = std::unordered_map<string_t, string_t>;

template <typename _Tp>
typedef struct redisObject {

    // 类型
    uint32_t type:4;

    // 编码
    uint32_t encoding:4;

    // 对象最后一次被访问的时间
    uint32_t lru:K_REDIS_LRU_BITS; /* lru time (relative to server.lruclock) */

    // 数据
    std::shared_ptr<_Tp> data_ptr;

} robj;

}//base_strc

}//redis_cpp


#endif ///CPLUSPLUS_REDIS_BASE_STRC_OBJECT
