
#ifndef __DL_HASH_DEF_H__
#define __DL_HASH_DEF_H__

#include <stdint.h>
#include <stdbool.h>
#include "jhash.h"
#include "khash.h"

/*
 * constraint:
 *     your struct name must complaince name_t,
 *     then you can DL_KHASH_DEF(name) to define your function.
 */

typedef int (*hash_traverse_func_t)(void *item, void *para);

/* 业务必须定义初始化hash表 */
#define DL_KHASH_DEF(name)                    \
    static khint_t name##_index(void *item)   \
    {                                         \
        name##_t *entry = (name##_t *)item;   \
        return jhash((const void*)&entry->key, sizeof(entry->key), 0);   \
    }                                         \
    static bool name##_cmp(void *item1, void *item2)                 \
    {                                         \
        name##_t *first = (name##_t *)item1;  \
        name##_t *second = (name##_t *)item2; \
        return memcmp(&first->key, &second->key, sizeof(first->key));   \
    }                                         \
    KHASH_INIT(name##_hash, void *, uint32_t, 0, name##_index, !(name##_cmp));  \
    khash_t(name##_hash) *name##_list;        \
    int name##_hash_insert(name##_t *arg)     \
    {                                         \
        int rv;                               \
        kh_put(name##_hash, name##_list, arg, &rv);                 \
        return 0;                             \
    }                                         \
    void name##_hash_remove(name##_t *arg)    \
    {                                         \
        khint_t k;                            \
        k = kh_get(name##_hash, name##_list, arg);                  \
        if (k == kh_end(name##_list)) {       \
            return;                           \
        }                                     \
        kh_del(name##_hash, name##_list, k);  \
    }                                         \
    name##_t *name##_hash_find(name##_t *arg) \
    {                                         \
        khint_t k;                            \
        if (arg == NULL) {                    \
            return NULL;                      \
        }                                     \
        k = kh_get(name##_hash, name##_list, arg);                  \
        if (k == kh_end(name##_list)) {       \
            return NULL;                      \
        }                                     \
        return (name##_t *)(kh_key(name##_list, k));                \
    }                                         \
    int name##_hash_traverse(hash_traverse_func_t func, void *arg)  \
    {                                         \
        khint_t k;                            \
        void *item;                           \
        int rv;                               \
        KH_FOR_EACH(name##_list, k) {         \
            item = kh_key(name##_list, k);    \
            rv = func(item, arg);             \
            if (rv != 0) {                    \
                return rv;                    \
            }                                 \
        }                                     \
        return 0;                             \
    }                                         \
    int name##_hash_size(void)                \
    {                                         \
        return (int)(kh_size(name##_list));   \
    }                                         \
    int name##_hash_init(void)                \
    {                                         \
        name##_list = kh_init(name##_hash);   \
        return 0;                             \
    }

/* 以下定义hash操作接口，业务根据需要选择是否采用这种方式，非必须  */
#define DL_HASH_OP(name)                      \
    static name##_t *name##_cache_alloc(void) \
    {                                         \
        name##_t *obj;                        \
        obj = (name##_t *)malloc(sizeof(name##_t));          \
        if (obj) {                            \
            name##_cache_obj_init(obj);       \
        }                                     \
        return obj;                           \
    }                                         \
    name##_t *name##_cache_create(name##_t **obj, name##_t *in)    \
    {                                          \
        *obj = name##_hash_find(in);           \
        if (*obj != NULL) {                    \
            name##_app_attr_copy(*obj, in);    \
            return *obj;                       \
        }                                      \
        *obj = name##_cache_alloc();           \
        if (obj == NULL) {                     \
            return NULL;                       \
        }                                      \
        memcpy(&(*obj)->key, &in->key, sizeof((*obj)->key));    \
        name##_app_attr_copy(*obj, in);        \
        name##_hash_insert(*obj);              \
        return *obj;                           \
    }                                          \
    static void name##_cache_free(name##_t *obj)            \
    {                                          \
        if (obj != NULL) {                     \
            free(obj);                         \
        }                                      \
        return;                                \
    }                                          \
    void name##_cache_destroy(name##_t *obj)   \
    {                                          \
        name##_hash_remove(obj);               \
        name##_cache_free(obj);                \
        return;                                \
    }

/**
 * @ name: 唯一标识一张hash表
 * @ in  : 要查找的对象信息(obj 和 in 的数据类型要一致)
 * @ obj ：hash表创建的指针地址, 创建失败 obj = NULL
 * @ 返回：创建失败，返回NULL
 */
#define DL_CACHE_CREATE(name, obj, in)    name##_cache_create(&(obj), (in))

/**
 * @ name: 唯一标识一张hash表
 * @ in  : 要查找的对象信息(obj 和 in 的数据类型要一致)
 * @ 返回：成功返回hash中item指针节点，失败返回NULL
 */
#define DL_CACHE_GET(name, in)    name##_hash_find(in)

/**
 * @ name: 唯一标识一张hash表
 * @ obj ：hash表中的item指针
 * @ 返回：void
 */
#define DL_CACHE_DESTROY(name, obj)    name##_cache_destroy(obj)

/**
 * @ name: 唯一标识一张hash表
 * @ func：遍历hash表的处理函数
 * @ arg: 入参
 * @ 返回：int类型, 入参 func 函数的返回值
 */
#define DL_CACHE_TRAVERSE(name, func, arg)    name##_hash_traverse(func, arg)

#endif /* __DL_HASH_DEF_H__ */

