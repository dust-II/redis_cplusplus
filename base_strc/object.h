#ifndef CPLUSPLUS_REDIS_BASE_STRC_OBJECT
#define CPLUSPLUS_REDIS_BASE_STRC_OBJECT

#include <stdint.h>
#include <memory>
#include "base_strc/data_types.h"

namespace redis {

/* The actual Redis Object */
/*
 * Redis 对象
 */

static constexpr uint8_t  K_REDIS_LRU_BITS = 24;
static constexpr uint32_t k_REDIS_LRU_CLOCK_MAX ((1<<K_REDIS_LRU_BITS)-1); /* Max value of obj->lru */
static constexpr uint32_t K_REDIS_LRU_CLOCK_RESOLUTION = 1000; /* LRU clock resolution in ms */

class Robj {
public:
    enum class Et
    {
        UNKNOW = 0,
        STRING = 1,
        LIST   = 2,
        SET    = 3,
        HASH   = 4
    };

public:
    Robj():type(Et::UNKNOW), encoding(0), lru(0), data_ptr(nullptr)
    {}

    Robj(Et t): type(t){
        switch (t) {
        case Et::STRING:
            data_ptr = std::make_shared<string_t>();break;
        case Et::LIST:
            data_ptr = std::make_shared<list_t>();break;
        case Et::SET:
            data_ptr = std::make_shared<set_t>();break;
        case Et::HASH:
            data_ptr = std::make_shared<hash_t>();break;
        default:
            break;
        }
    }

    // 类型
    Et type;

    // 编码
    uint32_t encoding:8; /*reserved*/

    // 对象最后一次被访问的时间
    uint32_t lru:K_REDIS_LRU_BITS; /* lru time (relative to server.lruclock) */

    // 数据
    std::shared_ptr<void> data_ptr;
};

}//redis


#endif ///CPLUSPLUS_REDIS_BASE_STRC_OBJECT
