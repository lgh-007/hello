#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) {
	int i,num;
	
	scanf("%d",&num);
	getchar();
	int arr[num][num];
	char array[num][10000];
	char *p;
	int cnt,u,v,k,m,n;
	memset(arr,0,sizeof(arr));
	for(i = 0;i<num;i++){
		p = &array[i][0];
		cnt = 0;
		fgets(array[i],10000,stdin);
		
		while(*p!='\n'){
				
				if(*p == ' ')
				{
					cnt++;
					p++;
				}
				arr[i][cnt] = arr[i][cnt]*10+(*p - '0');
				p++;		
		}
	}
	for (k = 0;k < num;k++){
		for (u = 0;u < num;u++){
			for (v = 0;v < num;v++){
				if(arr[u][k]!=0&&(arr[k][v]!=0)&&(arr[u][v]>= arr[u][k]+arr[k][v]||arr[u][v] ==0)){
					arr[u][v]= arr[u][k]+arr[k][v];
				}
				if(u==v){
					arr[u][v] = 0;
				}
			}
		}
	}
	
	for (m = 0;m < num;m++){
		for (n = 0;n < num;n++){
			if(arr[m][n] == 0&&m!=n){
				arr[m][n] = -1;
			}
			printf("%d ",arr[m][n]);
			
		}
		printf("\n");
	}

	
	return 0;
}
