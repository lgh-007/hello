#include <stdio.h>
#include <stdlib.h>
/*
��ĿҪ��
	��x,y,w,h��ʾ����ϵ�е�һ�����Σ�����(x,y)Ϊ�������Ͻǵ�����꣬w��h�ֱ��ʾ���εĿ�͸ߣ�
����ʱ�÷ֺŷָ�Ķ�����β���������������εĹ����ཻ���μ��������������Ķ�����β��ཻ��
�����Error��
���룺1,2,2,1;2,4,1,3;1,2,2,2
�����[2,2,1,1]  1
˼·��������غϲ��֣��ж��غϳɹ������xy���򷵻�err��
*/

struct tran{
	int x;/*���Ͻǵ�x������*/
	int y;/*���Ͻǵ�y������*/
	int w;/*��*/
	int h;/*��*/
};/*���ڴ�ž��󳤿����ϽǶ�������*/

/*������*/
int main(int argc, char *argv[]) {
	struct tran arr[10];/*������ʮ������*/
	struct tran tmp;/*���Դ��ÿ�������ཻ��ľ���*/
	int area,j;
	char str[100];//�ٶ������ַ�������һ��
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
	tmp.x = arr[0].x;/*�����һ������*/
	tmp.y = arr[0].y;
	tmp.w = arr[0].w;
	tmp.h = arr[0].h;
	for(j = 1;j<i;j++){
		if(tmp.x<arr[j].x){/*���w���غϲ���*/
			tmp.w = tmp.x+tmp.w-arr[j].x;
		}else if(tmp.x>arr[j].x){
			tmp.w = arr[j].x+arr[j].w-tmp.x;
		}else{
			if(tmp.w>=arr[j].w){
				tmp.w = arr[j].w;
			}
		}
		if(tmp.y<arr[j].y){/*���h���غϲ���*/
			tmp.h = arr[j].h-(arr[j].y-tmp.y);
		}else if(tmp.x>arr[j].x){
			tmp.h = tmp.h-(tmp.y-arr[j].y);
		}else{
			if(tmp.h>=arr[j].h){
				tmp.h = arr[j].h;
			}
		}
		if(tmp.w>0&&tmp.h>0){/*�������غϵ�������  ��������x��y��*/
			if(tmp.x<=arr[j].x){
				tmp.x = arr[j].x;
			}
			if(tmp.y>=arr[j].y){
				tmp.y = arr[j].y;
			}
		}else{
			break;
		}
	}/*forѭ������*/

	if(tmp.w>0&&tmp.h>0){
		area = tmp.w*tmp.h;
		printf("[%d,%d,%d,%d]  %d",tmp.x,tmp.y,tmp.w,tmp.h,area);
	}
	else{
		printf("Error");
	}
	return 0;
}
