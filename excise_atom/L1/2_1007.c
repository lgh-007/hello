#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int day[12] = {31,28,31,30, 31,30,31,31,30,31,30,31};
	
	char arr[12] ;
	int array[3] = {0},sum = 0,i = 0,j;
	char *p = arr;
	
	int a,b;
	gets(arr);
	a = '0' - '0';
	b = '2'-'0';

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
	
	for(j = 0;j<array[1]-1;j++)
	{
		sum += day[j];
		
	}
	sum += array[2];
	if(array[0]%4==0&&array[0]%100!=0||array[0]%400==0)
	{
		sum++;
	}
	printf("%d\n",sum);
	return 0;
	return 0;
}
