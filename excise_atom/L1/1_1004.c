#include <stdio.h>
#include <stdlib.h>

/* 在一个N*N的方阵中，填入1，2，……N*N个数，并要求构成如下的格式：
例如：
N=5
13 14 15 16  1
12 23 24 17  2
11 22 25 18  3
10 21 20 19  4
 9  8  7  6  5
  */

int main(int argc, char *argv[]) {

	int n;
  int row,line;
  int cnt,i,j,times;
  int **arr = NULL;
	while(scanf("%d",&n)!=EOF){
    cnt = 1;
    arr = (int**)malloc(sizeof(int*)*n);//为二维数组分配3行
    for (i = 0; i < n; i++){//为每列分配4个大小空间
        arr[i] = (int*)malloc(sizeof(int)*n);
    }

    for(times = 0;times<=n/2;times++)
    {
      for(row = times,line = n-1-times;row<n-1-times;row++)
      {
        arr[row][line] = cnt++;
      }
  //
      for(row = n-1-times,line = n-1 -times;line>times;line--)
      {
        arr[row][line] = cnt++;
      }
  //
      for(row = n-1-times,line = times;row>times;row--)
      {
        arr[row][line] = cnt++;
      }
  //
      for(row = times,line = times;line<n-1-times;line++)
      {
        arr[row][line] = cnt++;
      }
    }/* for（times）循环结束 */
     if(n%2 == 1)
     {
        arr[n/2] [n/2] = cnt;
     }
     for (i = 0;i<n;i++)
     {
        for(j = 0;j<n;j++)
        {
					if(n==1){
						printf(" %d",arr[i][j]);
					}else if(n==3){
						printf(" %d",arr[i][j]);
						printf(" ");
					}else{
						printf("%d ",arr[i][j]);
					}
        }
      printf("\n");
     }
  }/* while结束 */

	return 0;
}
