#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
��ĿҪ��
ʵ���и���һ����������������������м�ˮƽmeֵ
�����������ֵΪ������������ȡ����
����
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
���
99
521
˼·���Ƚ�������������ֱ���������ȥ�м�ֵ
*/

#define MAX 100000
/*���м�ֵ*/
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
/*������*/
int main(int argc, char *argv[]) {
/*�������壺*/
	int i,tmp;
	int *arr;/*��̬������ʱ����������meֵ*/
	int array[MAX];/*Ӧ��Ū����̬����*/
	int *p;

	i = 0;
	while(scanf("%d",&array[i])){/*�����������*/
		if(array[i] == 0)
			break;
		i++;
	}
	p = array;
	while(*p!=0){/*���ηֿ���Ӧ������Ȼ����������м�ֵ*/
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
