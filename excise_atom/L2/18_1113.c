#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//任意10以下的进制转化成十进制 
int todec(int a,int type)
{
	int num = 0;
	int i = 0;
	int tmp = 0;
	while(a!=0)
	{	
		tmp = a%10;
		a = a/10;
		num += tmp*pow(type,i++);
	}
	return num;
}
//
char* totpyes(int a,int type)
{
	static char* result1[100] = {0};
	char *test = result1;

	int i = 0;
	int tmp = 0;
	
	do{
		tmp = a % type;
		if(type>0)
		a /=type;
		test[i] = tmp+'0';
		i++;
	}while(a>0);
	return test;
	
}
int main(int argc, char *argv[]) {
	char str[20] = {0};
	char *p;
	int i,j;
	char *result;
	char result2[100] = {0};
	int tmp;
	int len;
	int array[3] = {0};
	gets(str);
			
		p = str;
		i = 0;
		while(*p != '\0'){
			if(*p == '<'||*p == '>')
			{
				 i++;
				 p++;
			}
			array[i] = (array[i]*10 + (*p - '0'));
			p++;
		}
		if(array[1]==10){
			result = totpyes(array[0],array[2]);
		}
		else{
			tmp = todec(array[0],array[1]);
			result = totpyes(tmp,array[2]);
		}
		len = strlen(result);
		for(j = 0;j<len;j++)
		{
			result2[j] = result[len-j-1];
		}
		printf("%d<%d>=%s<%d>\n",array[0],array[1],result2,array[2]);
		memset(array,0,sizeof(str));	
	


//	int test;
//	int val = 10111;
//	test = todec(val,2);
//	printf("%d\n",test);
//	test = totpyes(test,8);
//	printf("%d\n",test);
	
	return 0;
}
