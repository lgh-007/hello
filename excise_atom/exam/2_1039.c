#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
题目要求：
实验中给定一组无序的样本请计算出它的中间水平me值
（如果所计算值为浮点数则向下取整）
输入
1
99
13
110
212
521
319
415
953
419
492
726
825
828
962
983
0
输出
99
521
思路：先将输入存入数组后分别排序排序去中间值
*/

#define MAX 100000
/*求中间值*/
void getme(int* a,int len){
	int tmp,i,j;
	int me = (len-1)/2;

	if(len == 1){
		printf("%d\n",a[0]);
		return;
	}
	for(i = 0;i<len;i++){
		for (j = 0;j<len-i-1;j++){
			if(a[j]>a[j+1]){
				tmp = a[j+1];
				a[j+1] = a[j];
				a[j] = tmp;
			}
		}
	}
	printf("%d\n",a[me]);
}
/*主函数*/
int main(int argc, char *argv[]) {
/*变量定义：*/
	int i,tmp;
	int *arr;/*动态申请临时数组排序求me值*/
	int array[MAX];/*应该弄个动态数组*/
	int *p;

	i = 0;
	while(scanf("%d",&array[i])){/*输入存入数组*/
		if(array[i] == 0)
			break;
		i++;
	}
	p = array;
	while(*p!=0){/*依次分开对应的数组然后排序输出中间值*/
		tmp = *p;
		arr = (int*)malloc(sizeof(int)*tmp);
    for(i = 0;i<tmp;i++){
    		p++;
    		arr[i] = *p;
		}
		getme(arr,tmp);
		free(arr);
		p++;
	}
	return 0;
}
