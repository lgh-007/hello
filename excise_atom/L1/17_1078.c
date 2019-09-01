#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char arr[100];
	int times,i = 0,flag = 0,length;
	
	gets(arr);
	length = strlen(arr);
	times = (length+1)/2;
	char *pa = &arr[0];
	char *pb = &arr[length-2];
	
	while(i<times)
	{
		if(*pa != *pb)
		{
			flag = 1;
		}
		i++;
		pa++;
		pb--;
	}
	if(flag == 1){
		puts("No");
	}
	else{
		puts("Yes");
	}
	
	
	return 0;
}
