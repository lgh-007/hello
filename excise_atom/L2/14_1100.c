#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char arr[50];
	int height;
	int i = 0,j = 0,num = 0;
	int array[10] = {0};
	char *p;

	
	p = arr;
	gets(arr);
	scanf("%d",&height);
	
	while(*p!= '\0')
	{
		if(*p == ' ')
		{
			 i++;
			 p++;
		}
		array[i] =array[i]*10 + (*p - '0');
		p++;
	}
	for(;j<10;j++)
	{
		if((height+30)>=array[j])
		{
			num++;
		}
		
	}
	printf("%d\n",num);
	return 0;
}
