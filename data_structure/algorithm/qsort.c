#include <stdio.h>
#include <stdlib.h>

/*split�㷨����*/
void swap1(int *a,int *b){
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
void swap2(int *a,int *b){
  /*�мǲ������ͬһ����ַ���в�����*/
  printf("�滻ǰ%d %d\n", *a,*b);
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
  printf("�滻��%d %d\n", *a , *b );
}
void swap3(int *a,int *b){
  /*�мǲ������ͬһ����ַ���в�����*/
  *a^=*b;
  *b^=*a;
  *a^=*b;
}
/*������������ַ���*/
int split(int a[],int low,int high){
  int i , j , x;
  i = low;      /*iָ��Ƚ�Ԫ�ص�����λ��*/
  x = a[i];     /*���������һ��Ԫ������Ϊ�Ƚ�Ԫ��*/
  /*������ĵڶ���Ԫ����ʼ���������ҵ���Ԫ�ش��ڱȽ�Ԫ�أ�������*/
  for(j = low+1;j<=high;j++){
     /*���ҵ���С�ڱȽ�Ԫ�ص�����������ǰ��ϴ�������н���*/
    if(a[j]<=x){
      i++;
      if(i != j)
        swap3(&a[i],&a[j]);
    }
  }
  if(i != j){
    swap3(&a[low],&a[i]);   /*���Ƚ�Ԫ�ؽ���������λ��*/
  }
  return i;
}
int partition(int a[],int low,int high){
  int x = a[low];    //���������һ��Ԫ������Ϊ�Ƚ�Ԫ��
  int i = low;    //ָ������ͷ��ָ��
  int j = high;    //ָ������β��ָ��
  while (i < j)
  {
    while (i < j && a[j] >= x)
      j--;    //���������ҵ���һ��С�ڱȽ�Ԫ�ص���
    while (i < j && a[i] <= x)
      i++;    //���������ҵ���һ�����ڱȽ�Ԫ�ص���
    /*��Ҫע����ǣ������j--��i++��˳�򲻿��Ե�����
    ���������˳��i���߹�ͷ�������ڽ�����ϴ��Ԫ�ؽ��������鿪ͷ*/

    //��������С������
    if (i != j)
        swap1(&a[i], &a[j]);
  }
  swap1(&a[low], &a[i]);    //���Ƚ�Ԫ�ؽ���������λ��
  return i;    //���رȽ�Ԫ�ص�λ��
}
int quicksort(int a[],int low,int high){
  if (low < high){
    // int i = split(a, low, high);  /*�������鲢��ñȽ�Ԫ��λ��*/
    int i = partition(a, low, high);
    quicksort(a, low, i - 1);     /*�ԱȽ�Ԫ����߽�������*/
    quicksort(a, i + 1, high);    /*�ԱȽ�Ԫ���ұ߽�������*/
  }
}
/*��������*/
void InsertionSort(int *num,int n){
  int i,j,tmp;
  for(i = 1;i<n;i++){
    tmp = num[i];
    j = i-1;
    while (j >= 0 && tmp < num[j]) {
      num[j+1] = num[j];//�����ƶ�һ��
      j--;
    }
    num[j+1] = tmp;//��Ԫ�ز��롣
  }
}
/*ϵͳ�Դ��⺯����ʹ��*/
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
