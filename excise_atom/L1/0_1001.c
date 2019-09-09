#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int compare(char str1[],char str2[],int length)
{
	int cnt = 0, i;
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
	char stra[100];
	char strb[100];
	int times = 0,num;
	char *pa = NULL,*pb = NULL;
	int i, j, cnt = 0;
	int pa_cnt = 0, pb_cnt = 0;
	int pa_flag = 0, pb_flag = 0;

	gets(str);
	num = strlen(str);

	pa = &str[0];
	pb = &str[num-1];
    for(i = 0;i<num;i++){
        if(str[i] == ' '){
            times++;
        }
    }
    i = j = 0;
    times = (times+1)/2;
	while(i < times && j < times)
	{
		if(*pa == ' ' && pa_flag == 0){
			pa_flag = 1;
            i++;
		}
		if(*pb == ' ' && pb_flag == 0){
			pb_flag = 1;
            j++;
		}
		if (pa_flag == 0) {
			stra[pa_cnt++] = *pa;
			pa++;
		}
		if (pb_flag == 0) {
			strb[pb_cnt++] = *pb;
			pb--;
		}
//how is you you are how
		if (pa_flag == 1 && pb_flag == 1){
			if (pa_cnt == pb_cnt){
			    if(compare(stra,strb,pa_cnt)){
                    cnt++;
                }
			}
            memset(stra, 0, sizeof(stra));
            memset(strb, 0, sizeof(strb));
			pa++;
			pb--;
			pb_flag = 0;
			pa_flag = 0;
			pa_cnt = pb_cnt = 0;
		}
	}
	printf("%d",cnt);
	return 0;
}
