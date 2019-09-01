#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */\
int divisor(int a, int b)
{
	int m,n,result = 0;
	m = a;
	n = b;
	while ( a!=b) {
		if (a>b) a=a-b;
		else b=b-a;	
	}
	result = m*n/a;
	return result;	
	
}

int main(int argc, char *argv[]) {

	char arr[20];
	long int array[2] = {0},i = 0;
	long int val;
	
	while(gets(arr)){
		char *p = arr;
		val = 0;
		memset(array,0,sizeof(array));
		
		while(*p!= '\0')
		{
			if(*p == ' ')
			{
				 i++;
				 p++;
			}
			array[i] = (array[i]*10 + (*p - '0'));
			p++;
		} 
		val = divisor (array[0],array[1]);
		i = 0;
		
		printf("%d\n",val);	
	}
	

	return 0;
}
