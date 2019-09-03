#include <stdio.h>
#include <stdlib.h>

/*split算法解析*/
void swap1(int *a,int *b){
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
void swap2(int *a,int *b){
  /*切记不能针对同一个地址进行操作。*/
  printf("替换前%d %d\n", *a,*b);
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
  printf("替换后%d %d\n", *a , *b );
}
void swap3(int *a,int *b){
  /*切记不能针对同一个地址进行操作。*/
  *a^=*b;
  *b^=*a;
  *a^=*b;
}
/*快速排序的两种方法*/
int split(int a[],int low,int high){
  int i , j , x;
  i = low;      /*i指向比较元素的期望位置*/
  x = a[i];     /*将该数组第一个元素设置为比较元素*/
  /*从数组的第二个元素起开始遍历，若找到的元素大于比较元素，则跳过*/
  for(j = low+1;j<=high;j++){
     /*若找到了小于比较元素的数，则将其与前面较大的数进行交换*/
    if(a[j]<=x){
      i++;
      if(i != j)
        swap3(&a[i],&a[j]);
    }
  }
  if(i != j){
    swap3(&a[low],&a[i]);   /*将比较元素交换到期望位置*/
  }
  return i;
}
int partition(int a[],int low,int high){
  int x = a[low];    //将该数组第一个元素设置为比较元素
  int i = low;    //指向数组头的指针
  int j = high;    //指向数组尾的指针
  while (i < j)
  {
    while (i < j && a[j] >= x)
      j--;    //从右至左找到第一个小于比较元素的数
    while (i < j && a[i] <= x)
      i++;    //从左至右找到第一个大于比较元素的数
    /*需要注意的是，这里的j--与i++的顺序不可以调换！
    如果调换了顺序，i会走过头，以至于将后面较大的元素交换到数组开头*/

    //将大数与小数交换
    if (i != j)
      swap1(&a[i], &a[j]);
  }
  swap1(&a[low], &a[i]);    //将比较元素交换到期望位置
  return i;    //返回比较元素的位置
}
int quicksort(int a[],int low,int high){
  if (low < high){
    // int i = split(a, low, high);  /*划分数组并获得比较元素位置*/
    int i = partition(a, low, high);
    quicksort(a, low, i - 1);     /*对比较元素左边进行排序*/
    quicksort(a, i + 1, high);    /*对比较元素右边进行排序*/
  }
}
/*插入排序*/
void InsertionSort(int *num,int n){
  int i,j,tmp;
  for(i = 1;i<n;i++){
    tmp = num[i];
    j = i-1;
    while (j >= 0 && tmp < num[j]) {
      num[j+1] = num[j];//往后移动一次
      j--;
    }
    num[j+1] = tmp;//将元素插入。
  }
}
/*系统自带库函数的使用*/
int inc (const void * a,const void *b){
  return *(int *)a - *(int *)b;
}

int main(int argc, char const *argv[]) {
  int a[] = {5,7,1,6,4,8,3,2};

  int length = sizeof(a) / sizeof(a[0]);
  // quicksort(a, 0, length - 1);
  // qsort(a,length,sizeof(a[0]),inc);
  InsertionSort(a,length);
  for (int i = 0; i < length; i++)
    printf("%d ", a[i]);
  printf("\n");
  return 0;
}
