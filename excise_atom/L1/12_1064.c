#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	char arr[100];
	char arr_out[100];
	int i = 0;
	char *p = arr;
	gets(arr);

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
	puts(arr_out);
	return 0;
}
