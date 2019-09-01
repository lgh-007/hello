#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX 1000 



int main(int argc, char *argv[]) {
	int one = 0;
	int zero = 0;
	int tmp_cnt;
	int i,tmp = 0;
	int cal;
	int num1 = 0,num2 = 0;
	for(i = 0;i<=MAX;i++){
		one = 0;
		cal = i;
		zero = 0;
		tmp_cnt =0;
		while(cal!=0){
			tmp = cal%10;
			cal = cal/10;
			if(tmp == 1)
			{
				one++;
			}
			tmp_cnt++;
		}
		zero = tmp_cnt-one;
		if(one>zero){
			num1++;
		}else{
			num2++;
		}
	} 
	printf("%d %d",num1,num2);
	return 0;
}
