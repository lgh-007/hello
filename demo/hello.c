/*
 * Copyright(C) 2005 Ruijie Network. All rights reserved.
 */
/*
 * hello.c
 * Original Author:  linguohui@ruijie.com.cn, 2019-9-3
 * ʵ�����¹���:
 * �ֱ��ڲ�ͬ�������˲�ͬ�������ڴ��ַ
 * �����ͷŲ����ڴ��ַ
 * ���������ڴ�ͳ�ƴ���Ĺ���
 */

#include "include/hello.h"

#define NUM 5

/**�ֱ��ڲ�ͬ�������˲�ͬ�����Ŀռ�,�Լ��ͷŲ��ֿռ�**/
void hello(void)
{
    int **test1, i;

    test1 = (int **)m_malloc(sizeof(int*) * NUM);
    for (i = 0; i < NUM; i++){
        test1[i] = (int*)m_malloc(sizeof(int) * 10);
    }

    for (i = 0; i < 3; i++){
        m_free(test1[i]);
    }
}
