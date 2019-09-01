#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num; 
	
	while(scanf("%d",&num)!=EOF){
		int arr[2*num];
		int arr1[2*num];	
		int i = 0,j = 0,k = 0;
		int cnt = 0;
		for(i = 0;i<2*num;i++)
		{
			arr[i] = i+1;
		}
		do{
			for(j = 0;j<num;j++)
			{
				arr1[2*j] = arr[num+j];
				arr1[2*j+1] = arr[j];
			}
			for(k= 0;k<2*num;k++){
				arr[k]=arr1[k];
			}
			cnt++;
			
		}while(arr[1]!=2);
		printf("%d\n",cnt);	
	}

	return 0;
}
