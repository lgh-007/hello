#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num,tmp,times,cur,unit,val;
	int arr[10] = {0};
	int cnt,begin,i;
	while(scanf("%d",&num) !=EOF)
	{
		
		cnt = 0;
		begin = 0;
		i = 0;
		tmp = num;
		times = 0;
		while(tmp!=0)
		{
			//times;
			val = num % (int)(pow(10,times));//每次的个位值吧 
			cur = tmp%10;//对应的个位数十位数的数值
			
			if(cur == 1){
				arr[times]+= val+1;
			}else if(cur == 2){
				arr[times]+= val+1;
				arr[times]+= pow(10,times);
			}else {
				if(cur!=0){
					arr[times]+= 2*pow(10,times);
				}
			}
	 		
			tmp = tmp/10;
				if(tmp != 0)
				arr[times] += 2*(tmp)*pow(10,times);
	
			
			times++;
		}
		for(;i<times;i++)
		{
			cnt += arr[i];
		}
		printf("%d\n",cnt);
		memset(arr,0,10);
	}

	
	return 0;
}

