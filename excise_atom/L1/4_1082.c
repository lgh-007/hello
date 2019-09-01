#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int next[100];
void getNext(char * p, int * next)
{
	next[0] = -1;
	int i = 0, j = -1;
 
	while (i < strlen(p)-1)
	{
		if (j == -1 || p[i] == p[j])
		{
			++i;
			++j;
			next[i] = j;
		}	
		else
			j = next[j];
	}
}
int KMP(char * t, char * p) 
{
	int i = 0; 
	int j = 0;
 	int test = strlen(t); 
 	int test1 = strlen(p); 
	while (i < test && j < test1)
	{
		if (j == -1 || t[i] == p[j]) 
		{
			i++;
           	j++;
		}
	 	else 
           	j = next[j];
    }
 
    if (j == strlen(p))
       return i - j +1;
    else 
       return 0;
}


int main(int argc, char *argv[]) {
	char str[100];
	char *p;
	int flag;
	int i,j,k;
	char a[100] = {0};
	char b[100] = {0};
	int result = 0;
	
	
	for(k = 0;k<3;k ++)
	{
		gets(str);

		p = str;
		flag = 1;
		i = j = 0;
		while(*p != '\0')
		{
			if (flag == 1){
				a[i++] = *p++;
			}else {
				b[j++] = *p++;
			}
			if (*p == ' ')
			{
				p++;
				flag = 0;
			}
		}
		getNext(b,next);
		result = KMP(a,b);
		memset(a,0,100);
		memset(b,0,100);
		printf("%d\n",result);		
	} 	
	return 0;
}

