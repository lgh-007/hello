#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char arr[41] = {0};
char exits[10] = "Not exist";
int real = 0;
char* test(char* m,char *n)
{
	char tmp = '0';
	int cnt =0;
	int flag =1;
	int mark = 0;
	int i = 0;
	char *p = arr;


	char *q = exits;
	switch(n[0]){
		case 'D':
			while(*m!='\0'){

				if(*m == n[2]&&flag ==1){
					m++;
					real = 1;
					flag =0;
				}
				arr[i++] = *m;
				m++;
			}

			arr[i] = *m;
			if(real){
				return p;
			}else{
				return q;
			}
			break;
		case 'I':
			while(*m!='\0'){

				if(*m == n[2]){
					real = 1;
					mark = cnt;
				}
				m++;
				cnt++;
			}
			m = m-cnt;
			for(i = 0;i<mark;i++){
				arr[i] = *m++;
			}
			arr[i] = n[4];
			while(*m!='.'){
				arr[++i] = *m++;
			}
			arr[++i] = *m;
			if(real){
				return p;
			}else{
				return q;
			}
			break;
		case 'R':
			while(*m!='\0'){
				if(*m == n[2]){
					real = 1;
					*m = n[4];
				}
				arr[i++] = *m;
				m++;
			}
			arr[i] = *m;
			if(real){
				return p;
			}else{
				return q;
			}
			break;
		default:
			break;
	}
}

int main(int argc, char *argv[]) {
	char s1[50];
	char s2[10];
//	while(gets(s1)){
	gets(s1);
	gets(s2);

	char *vll;
	vll = test(s1,s2);

	printf("%s\n",vll);
	memset(arr,0,41);
	real = 0;
//	}

	return 0;
}
