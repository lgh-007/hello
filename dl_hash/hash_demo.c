/*
 * dl_hash_demo.c
 *
 *  Created on: 2018-12-20
 *      Author: zhanglinlin@ruijie.com.cn
 */
#include <stdio.h>
#include <stdbool.h>
#include "dl_hash_def.h"

/*
 * 注意:
 *     1. 结构体中 key 名字固定，业务的key定义在key的结构体中，hash对整个key进行计算
 *     2. 结构体名字前缀必须和DL_KHASH_DEF注册的名字一致
 */
typedef struct {
    uint32_t    vid;
    uint32_t    ifx;
    uint32_t    val;
} ss_intf_key_t;

typedef struct {
    ss_intf_key_t key;
    uint32_t     attr;
} ss_intf_t;

/*
 * 1. 结构体各个属性初始化、各属性赋值函数，由业务自己定义；
 * 2. 约束：在 DL_HASH_OP之前需要声明这两个函数；
 * 3. 函数名约束：name##_cache_obj_init(), name##_app_attr_copy(), name 与注册hash的一致；
 */
static inline void ss_intf_cache_obj_init(ss_intf_t *ss_intf)
{
    memset(ss_intf, 0, sizeof(ss_intf[0]));
}

static inline void ss_intf_app_attr_copy(ss_intf_t *ss_intf_obj, ss_intf_t *ss_intf_in)
{
    ss_intf_obj->attr = ss_intf_in->attr;
}

/* 初始化hash表  */
DL_KHASH_DEF(ss_intf);

/* hash操作接口 */
DL_HASH_OP(ss_intf);

/*====================================hash 操作 demo=================================================*/

int  ss_intf_event_op(ss_intf_t *msg, bool is_add)
{
    ss_intf_t *obj;

    if (is_add) {
        if (NULL == DL_CACHE_CREATE(ss_intf, obj, msg)) {
            printf("create fail. \n");
        }
    } else {
        if (NULL == (obj = DL_CACHE_GET(ss_intf, msg))) {
            printf("not found. \n");
            return 0;
        }
        DL_CACHE_DESTROY(ss_intf, obj);
    }

    return 0;
}

/* =================================打印接口 demo======================================== */

static int ut_dump_intf_op(void *item, void *para)
{
    ss_intf_t *obj;
    int *lmt;

    lmt = (int *)para;
    if ((*lmt)-- == 0) {
        return -1;
    }

    obj = (ss_intf_t *)item;

    printf("%7d %7d %7d %7d\n", obj->key.vid, obj->key.ifx, obj->attr,obj->key.val);
    return 0;
}

static int intf_dump(int lmt)
{
    printf("dump-ss-intf:\n");
    printf("count:%d \n", ss_intf_hash_size());
    printf(" vid      ifx     attr  \n");
    printf("------- ------- ------- \n");
    DL_CACHE_TRAVERSE(ss_intf, ut_dump_intf_op, &lmt);

    return 0;
}

/*================================main=================================*/

int main(int argc, char *argv[])
{
    ss_intf_t tmp_obj;
    int dump_cnt;

    printf("\n>>>>==========demo start============\n");

    /* 先初始化hash */
    ss_intf_hash_init();

    /* 测试：插入、更新、移除一个item */
    memset(&tmp_obj, 0, sizeof(tmp_obj));
    tmp_obj.key.vid = 1;
    tmp_obj.key.ifx = 2;
    tmp_obj.key.val = 3;
    tmp_obj.attr    = 10;

    ss_intf_event_op(&tmp_obj, true);
    dump_cnt = -1;       /* -1表示全部打印 */
    intf_dump(dump_cnt); /* dump_cnt 表示要打印的表项数量 */

    tmp_obj.attr    = 20;
    ss_intf_event_op(&tmp_obj, true);
    dump_cnt = 1;
    intf_dump(dump_cnt);

    ss_intf_event_op(&tmp_obj, false);
    dump_cnt = -1;
    intf_dump(dump_cnt);

    printf("\n>>>>============demo end==============\n");

    return 0;
}
