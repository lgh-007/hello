#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num;/*��ʾ����ĵ�����*/
	while(scanf("%d",&num)!=EOF){
		int arr[num+1];/*���ڴ�ŵƵ�״̬0��ʾ�أ�1��ʾ��*/
		int i,j;
		int total = 0;/*ͳ�����յ����ĸ���*/
		int cnt = 0;
		int tmp;
		memset(arr,0,sizeof(arr));/*�������*/
		for(i=1;i<=num;i++){
			if(arr[i]==1){
				arr[i]=0;
			}
			else{
				arr[i]= 1;
			}
			tmp = num/i;/*��i����ı����ƽ��з�ת*/ 
			for(j = 2;j<=tmp;j++)
			{
				if(arr[i*j]==0){
					arr[i*j] = 1;
				}else{
					arr[i*j] = 0;
				}
			}
		}
		for(i = 0;i<=num;i++){
			if(arr[i] == 1){
				total++;
			}
		}
		printf("%d\n",total);	
	}

	return 0;
}
