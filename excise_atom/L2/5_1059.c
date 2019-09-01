#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAXSIZE 12500//输入数组的尺寸 
#define MAXRC   200//最大的行数 
typedef struct 
{
    int row, col;//行列 
    int value;//对应的非零值 
}Triple;
typedef struct
{
    Triple data[MAXSIZE + 1]; // 一维数组
    int rpos[MAXRC+1];		/* 各行第一个非0的位置表 */ 
    int rows, cols, nums;  //矩阵的行数，列数和非零元素个数
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
	Matrix s1,s2,s3;
	Matrix out;
	int row1,line1;
	int row2,line2;
	int out_cnt,cnt;
	char str[1000] = {0};
	char *p =str;
	int tmp = 0;
	int i,j = 1,k,m=1,flag = 0,rpos_flag;
	
	scanf("%d",&row1);
	scanf("%d",&line1);
	getchar();
	s1.rows = row1;
	s1.cols = line1;
	s1.rpos[m] = 0;
	for(i = 1;i<=row1;i++)
	{
		memset(str,0,sizeof(str));
		k = 1;
		rpos_flag = 1;
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
					s1.data[j].row = i;
					s1.data[j].col = k;
					s1.data[j].value = tmp;
					if(rpos_flag ==1){
						s1.rpos[m++] += k;
						rpos_flag = 0;
			    	}	
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
			if(*p == '\0'&&tmp != 0){
				s1.data[j].row = i;
				s1.data[j].col = k;
				s1.data[j].value = tmp;
				j++;
				tmp = 0;
			}
		}	
	}
	
	s1.nums = j;
	j = 0; 
	scanf("%d",&row2);
	scanf("%d",&line2);
	getchar();
	s2.rows = row2;
	s2.cols = line2;
	for(i = 1;i<=row2;i++)
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
					s2.data[j].row = i;
					s2.data[j].col = k;
					s2.data[j].value = tmp;
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
			if(*p == '\0'&&tmp != 0){
				s2.data[j].row = i;
				s2.data[j].col = k;
				s2.data[j].value = tmp;
				j++;
				tmp = 0;
			}
		}	
	}
	s2.nums = j;
	TransposeSMatrix(&s2,&s3);
	tmp = 0;
	out_cnt = 0;
	
	//都是还没考虑到为零矩阵的情况 
//	for(i = 1;i<=s1.row;i++){
//		for(j = 1;i<=s3.row;i++){
//			tmp = 0;
//			for(k = 1;k<=s1.nums;k++){
//				if(s1.data[k].row ==i){
//					tmp+=s1.data[k].value*
//				}
//			} 
//		}
//	}
//	cnt = s1.data[1].row+1;
//	
//	for(i = 1;i<s1.nums;i++){
//		if(s1.data[i].row>=cnt){
//			
//			out.data[out_cnt].value = tmp;
//			out.data[out_cnt].row = cnt;
//			out.data[out_cnt].col = s3.data[j].row; 
//			tmp = 0;
//			cnt = s1.data[i].row+1;
//			
//		}
//		for(j = 1;j<s3.nums;j++)
//		{
//			if(s1.data[i].row == s3.data[j].row&&s1.data[i].col == s3.data[j].col){
//				tmp+=s1.data[i].value*s3.data[j].value;
//				break;
//			}
//		}
//
//	}

	printf("%d ",0);
//	for(i = 1;i<=d.rows;i++){
//		for(j = 1;j<=d.cols;j++){
//			if(i==d.data[k].row&&j==d.data[k].col){
//				printf("%d ",d.data[k].value);
//				k++;
//			}else{
//				printf("%d ",0);
//			}
//		}
//		printf("\n");
//	}
	
	
	return 0;
}


