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

#include <stdio.h>
#include <stdlib.h>
#include "dl_hash_def.h"

typedef struct {
    uint32_t    line;   /*�ļ��µ��к�*/
    char*    filep;     /*�ļ���*/
} mem_stat_key_t;

typedef struct {
    mem_stat_key_t key;
    uint32_t     mem_alloced;  /*����ĳһ������ĳߴ��С*/
    uint32_t     alloc_times;  /*����ĳһ������Ĵ�����С*/
    int  type;                 /*����malloc  ��  free*/
} mem_stat_t;

/**��������ڵ�**/
typedef struct accumulate_info_s {
    int sum;     /*ͳ��һ��.c�ļ��µ�malloc��free����*/
    int type;    /*type = 1��ʾmalloc   type = 0��ʾfree*/
    char *filep; /*�ļ���*/
    struct accumulate_info_s* next;
}acc_info_t;

/**��ϣ���ʼ��**/
void mem_stat_init(void);

#define m_malloc(size) intf_mtrace_malloc(size, __FILE__, __LINE__)

#define m_free(ptr)    intf_mtrace_free(ptr, __FILE__, __LINE__)

/**freeͳ��**/
void intf_mtrace_free(void *mp, char *filep, int line);
/**mallocͳ��**/
char* intf_mtrace_malloc(size_t size, char *filep, int line);
/**�����ӡ**/
void info_printf(void);
/**���������Ƿ��ҵ�ƥ��**/
int is_find(acc_info_t* node,mem_stat_t *obj);
/**��ӡ����**/
void linklist_print(acc_info_t* node);
#endif
