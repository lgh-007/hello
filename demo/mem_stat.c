/*
 * Copyright(C) 2019 Ruijie Network. All rights reserved.
 */
/*
 * mem_stat.c
 * Original Author:  linguohui@ruijie.com.cn, 2019-9-3
 * 实现如下功能:
 * 对内存申请进行统计
 * 最终释放部分内存地址
 * 用来测试  内存统计代码的功能
 */

#include "include/mem_stat.h"

/**定义链表头**/
acc_info_t head = {.next = NULL};
/*
 * 1. 结构体各个属性初始化、各属性赋值函数，由业务自己定义；
 * 2. 约束：在 DL_HASH_OP之前需要声明这两个函数；
 * 3. 函数名约束：name##_cache_obj_init(), name##_app_attr_copy(), name 与注册hash的一致；
 */
static inline void mem_stat_cache_obj_init(mem_stat_t *mem_stat)
{
    memset(mem_stat, 0, sizeof(mem_stat[0]));
}
static inline void mem_stat_app_attr_copy(mem_stat_t *mem_stat_obj, mem_stat_t *mem_stat_in)
{
    mem_stat_obj->alloc_times = mem_stat_in->alloc_times;
}
/** 初始化hash表  **/
DL_KHASH_DEF(mem_stat);
/** hash操作接口 **/
DL_HASH_OP(mem_stat);
/**哈希表初始化**/
void mem_stat_init(void)
{
  mem_stat_hash_init();
}
/* =================================打印接口 demo======================================== */

static int ut_dump_intf_op(void *item, void *para)
{
    mem_stat_t *obj;
    int *lmt;

    lmt = (int *)para;
    if ((*lmt)-- == 0) {
        return -1;
    }
    obj = (mem_stat_t *)item;
    if (!is_find(&head,obj)) {
      acc_info_t* node;
      node = (acc_info_t*)malloc(sizeof(acc_info_t));
      node->sum = obj->alloc_times;
      node->type = obj->type;
      node->filep = obj->key.filep;
      node->next = head.next;
      head.next = node;
    }
    printf("%7s %7d %7d %7d %7d\n", obj->key.filep, obj->key.line,
        obj->alloc_times,obj->mem_alloced,obj->type);

    return 0;
}
/**打印输出**/
static int intf_dump(int lmt)
{
    printf("dump-ss-intf:\n");
    printf("count:%d \n", mem_stat_hash_size());
    printf(" filep    line    times   size   type \n");
    printf("------- ------- ------- ------- -------    \n");
    DL_CACHE_TRAVERSE(mem_stat, ut_dump_intf_op, &lmt);
    printf("------- ------- ------- ------- -------    \n");
    printf("------- ------- ------- ------- -------    \n");
    printf(" filep   sum     type \n");
    linklist_print(&head);

    return 0;
}
/**哈希表的 增加和更新**/
void intf_add(size_t size, char *filep, int line,int type)
{
    mem_stat_t *obj, tmp;

    memset(&tmp, 0, sizeof(tmp));
    tmp.key.filep = filep;
    tmp.key.line = line;
    if (NULL == (obj = DL_CACHE_GET(mem_stat, &tmp))) {
        tmp.alloc_times++;
        if (NULL == DL_CACHE_CREATE(mem_stat, obj, &tmp)) {
            printf("create fail. \n");
        }
        obj->mem_alloced = size;
        obj->type = type;
    } else {
        obj->alloc_times++;
        if (type == 1) {
            obj->mem_alloced += size;
        }
    }
}
/**malloc统计**/
char* intf_mtrace_malloc(size_t size, char *filep, int line)
{
    void *mp;
    mp = malloc(size);
    if (mp != NULL) {
        /* 内存申请计数加1 */
        intf_add(size,filep,line,1);
    }

    return mp;
}
/**free统计**/
void intf_mtrace_free(void *mp, char *filep, int line)
{
    mem_stat_t *obj,tmp;
    if (mp != NULL) {
        free(mp);
        /* 内存申请计数减1 */
        intf_add(0,filep,line,0);
    }

    return;
}
/**输出打印**/
void info_printf(void)
{
    int dump_cnt;
    dump_cnt = -1;       /* -1表示全部打印 */
    intf_dump(dump_cnt);
}
/**在链表中是否找到匹配**/
int is_find(acc_info_t* node, mem_stat_t *obj)
{
    while (node->next != NULL) {
        node = node->next;
        if (node->filep == obj->key.filep && node->type == obj->type) {
        node->sum += obj->alloc_times;

        return 1;
    }
  }
  
  return 0;
}
/**打印链表**/
void linklist_print(acc_info_t* node)
{
    while (node->next != NULL) {
        node = node->next;
        printf("%7s %7d %7d\n", node->filep, node->sum, node->type);
    }
}
