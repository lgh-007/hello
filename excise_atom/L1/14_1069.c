#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num1,num2;



	while(scanf("%d",&num1) != EOF){
		int times;
		char buff1[1000][100];
		char buff2[10000][100];
		int i = 0,j = 0,k = 0,h = 0,u = 0;
		int arr[100];
		char *pa,*pb; 
		int cnt1,cnt2;
		int flag = 0;
		getchar();
		for(;i<num1;i++)
		{
			fgets(buff1[i],100,stdin);
		}
		scanf("%d",&num2);	
		getchar();
		for(;j<num2;j++)
		{
		//	scanf("%s",&buff[i]) ;
			fgets(buff2[j],100,stdin);
		}
	
			
		for(k = 0;k<num2;k++)
		{
			flag = 0;
			for(u = 0;u<num1;u++)
			{
				cnt1 = cnt2 =0;
				pa = &buff2[k][0];
				pb = &buff1[u][0];
				while(*pb!=' ')
				{
					cnt2++;
					if(*pa==*pb)
					{
						cnt1++;
					}
					pa++;
					pb++;
				}
				if(cnt1 == cnt2)
				{
					flag = 1;
					break;
				}				
			}
			if(flag == 1)
			{
				printf("%s",buff1[u]);
				//puts(buff1[u]);
			}
			else{
				printf("No Answer!\n");
			}		
		}
	}		
	return 0;
}

