#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
��ĿҪ��
����һ�����飬��������ÿ����Ա�����ұ��ƶ�m�Σ�����ƶ�������飺
������������Ϊ[1 2 3 4 5]���ƶ�����Ϊ2�����Ϊ[4 5 1 2 3]
���룺
5
1 2 3 4 5
2
�����4 5 1 2 3
˼·��������һ�������mv�δ�ŵ�����ڴ����ǰ������
*/

/*������*/
int main(int argc, char *argv[]) {
	int mv,i,j,len,k;
	int *array,*out;/*���������������*/

	while(scanf("%d",&len) != EOF){
		getchar();/*��Żس���*/
		array = (int*)malloc(sizeof(int)*len);
		out = (int*)malloc(sizeof(int)*len);
		k = 0;
		for(i = 0;i<len;i++)
		{
			scanf("%d",&array[i]);
		}
		scanf("%d",&mv);
		getchar();/*��Żس���*/
		while(mv>len){/*����mv�������鳤��*/
			mv=mv-len;
		}
		for(j = 0;j<len;j++){
			if(j<len-mv){
				out[j+mv] = array[j];
			}
			else{
				out[k++] = array[j];
			}
		}
		for(i = 0;i<len;i++){/*������*/
			printf("%d ",out[i]);
		}
		free(array);
		free(out);
		printf("\n");
	}/*while����*/


	return 0;
}
