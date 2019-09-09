#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char arr[100];
	int array[100] = {0};
	char *p = arr;
	int lab[20] = {0};
	int i, j, mv , len ,sum ,tmp , mark;

	gets(arr);
	len = 0;
    // ‰»Î¥Ê∑≈µΩarray
	while (*p != '\0') {
		if (*p == ',') {
			 len++;
			 p += 2;
		}
		array[len] = (array[len] * 10 + (*p - '0'));
		p++;
	}


	sum = 0;
	mv = 0;
	j = 0;

	while(sum <= len){
		mv = array[sum];
		tmp = 0, mark = 0;
		if(sum+mv > len){
			sum = len;
			lab[j++] = len;
			break;
		}
		for(i = sum +1; i<= sum+mv; i++){
			if(tmp <= array[i]){
				tmp = array[i];
				mark = i;
			}
		}
		lab[j] = mark;
		j++;
		sum = mark;
	}

	printf("%d\n",j);
	printf("%d",array[0]);
	for (i = 0; i < j; i++) {
		printf(", %d",array[lab[i]]);
	}


	return 0;
}
