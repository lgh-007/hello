#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int compare(char str1[],char str2[],int length)
{
	int cnt = 0,i;
	for(i = 0;i<length;i++){
		if(str1[i] == str2[length-1-i]){
			cnt++;
		}
	}
	if(cnt == length){
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	char str[10000];
	char stra[10];
	char strb[10];
	int times,num;
	char *pa = NULL,*pb = NULL;
	int i= 0,j = 0,cnt = 0,result = 0;
	int pa_cnt = 0, pb_cnt = 0;
	static int pa_flag = 0, pb_flag = 0;

	gets(str);
	num = strlen(str);
	times = (num+1)/2;
	pa = &str[0];
	pb = &str[num-1];
	
	while(i < times)
	{
		if(*pa == ' '){
			pa_flag = 1;
		}
		if(*pb == ' '){
			pb_flag = 1;
		}
		if (pa_flag == 0){
			stra[pa_cnt++] = *pa;
			pa++;
		}
		if (pb_flag == 0){
			strb[pb_cnt++] = *pb;
			pb--;
		}
		
		if (pa_flag==1&&pb_flag==1){
			if (pa_cnt == pb_cnt){
			    result = compare(stra,strb,pa_cnt);
			    memset(stra, 0, sizeof(stra));
			    memset(strb, 0, sizeof(strb));
			    if(result == 1){
					cnt++;
					result = 0;
				}
				
			}
		    
			pa++;
			pb--;
			pb_flag = 0;
			pa_flag = 0;
			pa_cnt = pb_cnt = 0;
		}
		
		i++;
	}
	printf("%d",cnt);
	return 0;
}

