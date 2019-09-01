#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
题目要求：
输入一个数组，将数组中每个成员都向右边移动m次，输出移动后的数组：
例如输入数组为[1 2 3 4 5]，移动次数为2，输出为[4 5 1 2 3]
输入：
5
1 2 3 4 5
2
输出：4 5 1 2 3
思路：用另外一个数组从mv次存放到最后在存放在前几个。
*/

/*主函数*/
int main(int argc, char *argv[]) {
	int mv,i,j,len,k;
	int *array,*out;/*存放输入和输出数组*/

	while(scanf("%d",&len) != EOF){
		getchar();/*存放回车符*/
		array = (int*)malloc(sizeof(int)*len);
		out = (int*)malloc(sizeof(int)*len);
		k = 0;
		for(i = 0;i<len;i++)
		{
			scanf("%d",&array[i]);
		}
		scanf("%d",&mv);
		getchar();/*存放回车符*/
		while(mv>len){/*考虑mv大于数组长度*/
			mv=mv-len;
		}
		for(j = 0;j<len;j++){
			if(j<len-mv){
				out[j+mv] = array[j];
			}
			else{
				out[k++] = array[j];
			}
		}
		for(i = 0;i<len;i++){/*输出结果*/
			printf("%d ",out[i]);
		}
		free(array);
		free(out);
		printf("\n");
	}/*while结束*/


	return 0;
}
