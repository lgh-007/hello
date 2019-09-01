#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAXSIZE 12500
typedef struct
{
    int row, col;
    int value;
}Triple;
typedef struct
{
    Triple data[MAXSIZE + 1]; // һά����
    int rows, cols, nums;  //�����������������ͷ���Ԫ�ظ���
}Matrix;

int TransposeSMatrix(Matrix* M,Matrix* T){
	int p,q,col;
	(*T).rows = (*M).cols;
	(*T).cols = (*M).rows;
	(*T).nums = (*M).nums;
	if((*T).nums){
		q = 1;
		for(col = 1;col<=(*M).cols;col++){
			for(p = 1;p<=(*M).nums;p++){
				if((*M).data[p].col == col){
					(*T).data[q].row = (*M).data[p].col;
					(*T).data[q].col = (*M).data[p].row;
					(*T).data[q].value = (*M).data[p].value;
					++q;
				}
			}
		}
	}
	return 1;
}


int main(int argc, char *argv[]) {
	Matrix s,d;
	int row,line;
	char str[1000] = {0};
	char *p =str;
	int tmp = 0;
	scanf("%d",&row);
	scanf("%d",&line);
	getchar();
	s.rows = row;
	s.cols = line;
	int i,j = 1,k,flag = 0;

	for(i = 1;i<=row;i++)
	{
		memset(str,0,sizeof(str));
		k = 1;

		p = str;
		gets(str);

		while(*p != '\0')
		{
			if(*p == ' ')
			{
				if(flag == 1){
					tmp = tmp*(-1);
					flag = 0;
				}
				if(tmp != 0){
					s.data[j].row = i;
					s.data[j].col = k;
					s.data[j].value = tmp;
					j++;
				}
				tmp = 0;
				p++;
				k++;
			}
			if(*p == '-'){
				flag = 1;
			}else{
				tmp = tmp*10 + (*p-'0');
			}
			p++;
		}
	}

	s.nums = j;
	TransposeSMatrix(&s,&d);
	k = 1;
	for(i = 1;i<=d.rows;i++){
		for(j = 1;j<=d.cols;j++){
			if(i==d.data[k].row&&j==d.data[k].col){
				printf("%d ",d.data[k].value);
				k++;
			}else{
				printf("%d ",0);
			}
		}
		printf("\n");
	}


	return 0;
}
