/*
 * Copyright(C) 2019 Ruijie Network. All rights reserved.
 */
/*
 * mem_stat.h
 * Original Author:  linguohui@ruijie.com.cn, 2019-9-3
 *
 */

#ifndef _MEM_STAT_H__
#define _MEM_STAT_H__

#include "dl_hash_def.h"

enum types {
    FREE, MALLOC
};

typedef struct {
    uint32_t  line;   /* 文件下的行号 */
    char*     filep;  /* 文件名 */
} mem_stat_key_t;

typedef struct {
    mem_stat_key_t key;
    uint32_t       mem_alloced;    /* 具体某一行申请的尺寸大小 */
    uint32_t       times;          /* 具体某一行申请和释放的次数大小 */
    enum types      type;           /* 区分malloc  和  free */
} mem_stat_t;

/* 定义链表结构体 */
typedef struct acc_info_s {
    int   sum;     /* 统计一个.c文件下的malloc或free数量 */
    int   type;    /* type = 1表示malloc   type = 0表示free */
    char *filep;   /* 文件名 */
    struct acc_info_s* next;
} acc_info_t;

/* 哈希表初始化 */
void mem_stat_init(void);

#define m_malloc(size) intf_mtrace_malloc(size, __FILE__, __LINE__)

#define m_free(ptr)    intf_mtrace_free(ptr, __FILE__, __LINE__)

/* free统计 */
void intf_mtrace_free(void *mp, char *filep, int line);

/* malloc统计 */
char* intf_mtrace_malloc(size_t size, char *filep, int line);

/* 输出打印 */
void info_printf(void);

/* 查找链表 */
bool is_find(acc_info_t* node, mem_stat_t *obj);

/* 打印链表 */
void linklist_print(acc_info_t* node);

#endif /* _MEM_STAT_H__ */
