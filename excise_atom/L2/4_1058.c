#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int row,line;
	
	char str[100] = {0};
	char *p =str;
	scanf("%d",&row);
	scanf("%d",&line);
	getchar();
	int i,j,k,flag = 0;
	int array[row][line];
	memset(array,0,sizeof(array));
	for(i = 0;i<row;i++)
	{
		memset(str,0,sizeof(str));
		k = 0;
		p = str;
		gets(str);
		
	
		while(*p != '\0')
		{
			if(*p == ' ')
			{	
				if(flag ==1 ){
					array[i][k] = array[i][k]*(-1);
					flag = 0;
				}
				p++;
				k++;		
			}
			if(*p == '-'){
				flag = 1;
			}else{
				array[i][k] = array[i][k]*10 + (*p-'0');	
			}
			
			p++;
		}	
	}
	
	for(i = 0;i<line;i++)
	{
		for(j = 0;j<row;j++)
		{
			printf("%d ",array[j][i]);
		}
		printf("\n");
	}
	
	
	printf("%d\n",row);
	printf("%d\n",line);
	return 0;
}

