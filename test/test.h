#ifndef _TEST_H__
#define _TEST_H__

#include <stdio.h>
#include <stdlib.h>
#include "dl_hash_def.h"


typedef struct {
    uint32_t    line;
    char*    filep;
} detail_key_t;

typedef struct {
    detail_key_t key;
    uint32_t     alloc_times;
} detail_t;


typedef struct intf_mtrace_info_s {
    int count;
    unsigned int mem_alloced;
    char *filep;
    int line;
    int times;
    void* mp;
    struct intf_mtrace_info_s* next;
}intf_mtrace_info_t;

void test();
#define m_malloc(size) intf_mtrace_malloc(size, __FILE__, __LINE__)
// #define m_calloc(size) m_perform_calloc(size, __FILE__, __LINE__)
#define m_free(ptr)    intf_mtrace_free(ptr, __FILE__, __LINE__)//

// #define m_printf()  info_printf(&head);
void intf_mtrace_free(void *mp, char *filep, int line);
// char* m_perform_calloc(size_t size, const char *filep, int line);
char* intf_mtrace_malloc(size_t size, char *filep, int line);

void info_printf();
int is_find(intf_mtrace_info_t* node,size_t size,char *filep,int line);
int is_free(intf_mtrace_info_t* node,char *file,void* mp);
#endif
