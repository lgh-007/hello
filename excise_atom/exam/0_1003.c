#include <stdio.h>
#include <stdlib.h>
/*
题目要求：
	用x,y,w,h表示坐标系中的一个矩形，其中(x,y)为矩形左上角点的坐标，w和h分别表示矩形的宽和高，
输入时用分号分割的多个矩形参数，输出这多个矩形的公共相交矩形及其面积，若输入的多个矩形不相交，
则输出Error。
输入：1,2,2,1;2,4,1,3;1,2,2,2
输出：[2,2,1,1]  1
思路：先求出重合部分，判断重合成功则求出xy否则返回err。
*/

struct tran{
	int x;/*左上角的x轴坐标*/
	int y;/*左上角的y轴坐标*/
	int w;/*宽*/
	int h;/*高*/
};/*用于存放矩阵长宽左上角定点坐标*/

/*主函数*/
int main(int argc, char *argv[]) {
	struct tran arr[10];/*不超过十个矩阵*/
	struct tran tmp;/*用以存放每次两两相交后的矩阵*/
	int area,j;
	char str[100];//假定输入字符不超过一百
	char *p = str;
	int i = 0;

	//fgets(str,100,stdin);
  gets(str);
	while(*p!='\0'){
		if(*p==';'){
			p++;
		}
		arr[i].x = *p-'0';
		p+=2;
		arr[i].y = *p-'0';
		p+=2;
		arr[i].w = *p-'0';
		p+=2;
		arr[i].h = *p-'0';
		p++;
		i++;
	}
	tmp.x = arr[0].x;/*输入第一个矩阵*/
	tmp.y = arr[0].y;
	tmp.w = arr[0].w;
	tmp.h = arr[0].h;
	for(j = 1;j<i;j++){
		if(tmp.x<arr[j].x){/*求出w的重合部分*/
			tmp.w = tmp.x+tmp.w-arr[j].x;
		}else if(tmp.x>arr[j].x){
			tmp.w = arr[j].x+arr[j].w-tmp.x;
		}else{
			if(tmp.w>=arr[j].w){
				tmp.w = arr[j].w;
			}
		}
		if(tmp.y<arr[j].y){/*求出h的重合部分*/
			tmp.h = arr[j].h-(arr[j].y-tmp.y);
		}else if(tmp.x>arr[j].x){
			tmp.h = tmp.h-(tmp.y-arr[j].y);
		}else{
			if(tmp.h>=arr[j].h){
				tmp.h = arr[j].h;
			}
		}
		if(tmp.w>0&&tmp.h>0){/*在满足重合的条件下  进来就求x和y。*/
			if(tmp.x<=arr[j].x){
				tmp.x = arr[j].x;
			}
			if(tmp.y>=arr[j].y){
				tmp.y = arr[j].y;
			}
		}else{
			break;
		}
	}/*for循环结束*/

	if(tmp.w>0&&tmp.h>0){
		area = tmp.w*tmp.h;
		printf("[%d,%d,%d,%d]  %d",tmp.x,tmp.y,tmp.w,tmp.h,area);
	}
	else{
		printf("Error");
	}
	return 0;
}
