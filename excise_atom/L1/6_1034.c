#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void mergeAdd(int arr[], int left, int mid, int right, int *temp){
	int i = left;
	int j = mid + 1;
	int k = left;//��ʱ�±�
	while (i <= mid&&j <= right){
		if (arr[i] < arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid){
		temp[k++] = arr[i++];
	}
	while (j <= right){
		temp[k++] = arr[j++];
	}
	//��temp�е����ݿ���arr������
	//���й鲢��ʱ�򣬴����������arr[left,right),��Ӧ�Ļ��
	//�ⲿ������������tmp[left,right)������
	memcpy(arr + left, temp + left, sizeof(int)*(right - left+1));
}
void mergeSort(int arr[],int left,int right,int *temp){//ʵ�֡��֡�
	int mid = 0;
	if (left < right){
		mid = left + (right - left) / 2;
		mergeSort(arr, left, mid, temp);
		mergeSort(arr, mid + 1, right, temp);
		mergeAdd(arr, left, mid, right, temp);
	}
	
}


int main(int argc, char *argv[]) {
	
//	int arr[] = { 8,4,5,7,1,3,6,2};
//	int i ;
//	int len = sizeof(arr)/sizeof(int);
//	int *temp = (int*)malloc(sizeof(int)*len);
// 
//	mergeSort(arr, 0, len - 1, temp);
//	
//	free(temp);
//	for (i= 0; i < len; i++){
//		printf("%d ", arr[i]);
//	} 

	int num;
	int len;
	int members[1000];
	sacnf("%d",num);
	int *temp;
	int i,j,k;
	for(i = 0;i<num;i++)
	{
		scanf("%d",len);
		for(j = 0;j<len;j++)
		{
			scanf("%d",members[j]);
		}
		temp = (int*)malloc(sizeof(int)*len);
		mergeSort(members, 0, len - 1, temp);
	}

	 
	return 0;
}
