#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char arr[200] = {0};
	char arr_out[200]={0}; 
	int i;
	char *p;
	while(gets(arr)){
		p = arr;
		i = 0;
		while(*p!= '\0')
		{
			if(*p == ' ')
			{
				 p++;
			}
			arr_out[i] = *p; 
			p++;
			i++;
		}
		if(strlen(arr_out)>100)
		{
			puts("Result String is cutted.");
		}
		else{
			puts(arr_out);	
		}
		
		memset(arr,0,100);
		memset(arr_out,0,100);
	}
	return 0;
}

