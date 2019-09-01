#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num;/*表示输入的灯数量*/
	while(scanf("%d",&num)!=EOF){
		int arr[num+1];/*用于存放灯的状态0表示关，1表示亮*/
		int i,j;
		int total = 0;/*统计最终灯亮的个数*/
		int cnt = 0;
		int tmp;
		memset(arr,0,sizeof(arr));/*清空数组*/
		for(i=1;i<=num;i++){
			if(arr[i]==1){
				arr[i]=0;
			}
			else{
				arr[i]= 1;
			}
			tmp = num/i;/*将i后面的倍数灯进行翻转*/ 
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
