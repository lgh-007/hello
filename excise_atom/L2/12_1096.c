#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//float Sn(float n)
//{	
//	if(n<=2){
//		return (float)(1/n+1);
//	}
//	else{
//		return (float)(1/n+Sn(n-1));
//	}
//} 
#define MAX  1673859
int main(int argc, char *argv[]) {
//	float test = 0;
//	test = Sn(3000);
//	printf("%f",test);
	int i;
	int k;
	double sum = 0;
	while(scanf("%d",&k)!=EOF){
		sum = 0;
		for(i = 1;i<MAX;i++)
		{
			sum+=(double)1/i;
			if(sum>k)
				break;
		}
		printf("%d\n",i);
	}
	return 0;

}
