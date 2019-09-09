/*
 * Copyright(C) 2019 Ruijie Network. All rights reserved.
 */
/*
 * mian.c
 * Original Author:  linguohui@ruijie.com.cn, 2019-9-3
 * 实现如下功能:
 * mem_stat.c测试
 */

#include <stdio.h>
#include <stdlib.h>
#include "include/mem_stat.h"
#include "include/hello.h"

/* 主函数 */
int main(int argc, char const *argv[])
{
    int **test1, i;

    mem_stat_init();
    hello();

    test1 = (int **)m_malloc(sizeof(int*) * 5);
    for (i = 0; i < 5; i++ ) {
        test1[i] = (int*)m_malloc(sizeof(int) * 10);
    }

    for (i = 0; i < 5; i++) {
        m_free(test1[i]);
    }
    m_free(test1);

    info_printf();

    return 0;
}
