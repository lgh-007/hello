#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int todec(char *a,int type,int len)
{
	int num = 0,test = 0;
	int tmp = 0;
	len--;
	while(*a != '\0')
	{
	
		switch(*a)
		{
			case 'a': tmp = 10;break;
			case 'b': tmp = 11;break;
			case 'c': tmp = 12;break;
			case 'd': tmp = 13;break;
			case 'e': tmp = 14;break;
			case 'f': tmp = 15;break;
			case 'g': tmp = 16;break;
			case 'h': tmp = 17;break;
			case 'i': tmp = 18;break;
			case 'j': tmp = 19;break;
			case 'k': tmp = 20;break;
			case 'l': tmp = 21;break;
			case 'm': tmp = 22;break;
			case 'n': tmp = 23;break;
			case 'o': tmp = 24;break;
			case 'p': tmp = 25;break;
			case 'q': tmp = 26;break;
			case 'r': tmp = 27;break;		
			case 's': tmp = 28;break;
			case 't': tmp = 29;break;
			case 'u': tmp = 30;break;
			case 'v': tmp = 31;break;
			case 'w': tmp = 32;break;
			case 'x': tmp = 33;break;
			case 'y': tmp = 34;break;
			case 'z': tmp = 35;break;
			
			case 'A':tmp = 10;break;
			case 'B':tmp = 11;break;
			case 'C':tmp = 12;break;
			case 'D':tmp = 13;break;
			case 'E':tmp = 14;break;
			case 'F':tmp = 15;break;
			case 'G': tmp = 16;break;
			case 'H': tmp = 17;break;
			case 'I': tmp = 18;break;
			case 'J': tmp = 19;break;
			case 'K': tmp = 20;break;
			case 'L': tmp = 21;break;
			case 'M': tmp = 22;break;
			case 'N': tmp = 23;break;
			case 'O': tmp = 24;break;
			case 'P': tmp = 25;break;
			case 'Q': tmp = 26;break;
			case 'R': tmp = 27;break;		
			case 'S': tmp = 28;break;
			case 'T': tmp = 29;break;
			case 'U': tmp = 30;break;
			case 'V': tmp = 31;break;
			case 'W': tmp = 32;break;
			case 'X': tmp = 33;break;
			case 'Y': tmp = 34;break;
			case 'Z': tmp = 35;break;
			default:break;
		}
		
		if(*a>='0'&&*a<='9'){
			num += (*a-'0')*pow(type,len);
		}
		else{
			num += tmp*pow(type,len);
		}
		len--;
		a++;
	}
	return num;
}
//int type_arr[10];
char* totpyes(int a,int type)
{
	static char arr[10];
	int i = 0,j = 0,len = 0;
	int tmp = 0;
	while(a>0)
	{
		tmp = a%type;
		if(tmp>9){
			switch(tmp)
			{
				case 10: arr[i] = 'a';break;
				case 11: arr[i] = 'b';break;
				case 12: arr[i] = 'c';break;
				case 13: arr[i] = 'd';break;
				case 14: arr[i] = 'e';break;
				case 15: arr[i] = 'f';break;
				case 16: arr[i] = 'g';break;
				case 17: arr[i] = 'h';break;
				case 18: arr[i] = 'i';break;
				case 19: arr[i] = 'j';break;
				case 20: arr[i] = 'k';break;
				case 21: arr[i] = 'l';break;
				case 22: arr[i] = 'm';break;
				case 23: arr[i] = 'n';break;
				case 24: arr[i] = '0';break;
				case 25: arr[i] = 'p';break;
				case 26: arr[i] = 'q';break;
				case 27: arr[i] = 'r';break;
				case 28: arr[i] = 's';break;
				case 29: arr[i] = 't';break;
				case 30: arr[i] = 'u';break;
				case 31: arr[i] = 'v';break;
				case 32: arr[i] = 'w';break;
				case 33: arr[i] = 'x';break;
				case 34: arr[i] = 'y';break;
				case 35: arr[i] = 'z';break;
		
				
				default:break;
			}
		}else{
			arr[i] = tmp+'0';	
		}
		
		a /=type;
		i++;
	}
	return arr;
	
}
int main(int argc, char *argv[]) {
	char str[10] = {0};
	char val[10] = {0};
	int array[2] = {0};
	int i = 0,j = 0;
	char *out;
	int dec_val;
	int len;
	int length;
	char *p = str;
	while(gets(str))
	{
		scanf("%s",&val);
	
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
			length = strlen(val);
			dec_val = todec(val,array[0],length);
			
			
			out = totpyes(dec_val,array[1]);
			len = strlen(out);
			for(j = len-1;j>=0;j--)
			{
				printf("%c",*(out+j));	
			}
			printf("\n");
		
	}
	

	
	
	return 0;
}
