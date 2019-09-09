/*
 * Copyright(C) 2005 Ruijie Network. All rights reserved.
 */
/*
 * hello.c
 * Original Author:  linguohui@ruijie.com.cn, 2019-9-3
 * 实现如下功能:
 * 分别在不同行申请了不同数量的内存地址
 * 最终释放部分内存地址
 * 用来测试内存统计代码的功能
 */

#include "include/hello.h"

/* 分别在不同行申请了不同数量的空间,以及释放部分空间 */
void hello(void)
{
    int **test1, i;

    test1 = (int **)m_malloc(sizeof(int*) * 5);
    for (i = 0; i < 5; i++) {
        test1[i] = (int*)m_malloc(sizeof(int) * 10);
    }

    for (i = 0; i < 3; i++) {
        m_free(test1[i]);
    }
}
