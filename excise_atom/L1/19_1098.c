#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x, y;
	scanf("%d%d", &x, &y);
	int *arr;
	int i, mv , cnt;
	arr = (int*)malloc(sizeof(int) * x);

	for(i = 0; i < x; i++){
		arr[i] = 0;
	}

	i = 0, cnt = 0 ,mv = -1;
	while (cnt != x-1) {
		if(arr[i] == 0){
			mv++;
			if(mv == y-1){
				arr[i] = 1;
				mv = -1;
				cnt++;
			}
		}
		i++;
		if(i == x)  {
			i = 0;
		}
	}
	for(i = 0; i < x; i++){
		if(arr[i] == 0){
			printf("%d",i);
			break;
		}
	}


	return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// /* ���嵥���������� */
// typedef struct LNode {
//   int data;       /* ���� */
//   struct LNode *next;  /* ��һ����ָ���� */
// }LNode,*Linklist;
// /*���ܣ�����һ������Ϊn������*/
// LNode* createlist(int n){
//     LNode *head,*node,*end;/* ����ͷ���,��ͨ��㣬β���  */
//     int i;
//     head = (LNode*)malloc(sizeof(LNode));/* �����ַ */
//     end = head;/* ���ǿ�������ͷβ�ڵ�һ��  */
//     for(i = 1; i < n; i++){
//         node = (LNode*)malloc(sizeof(LNode));
//         node->data = i;
//         end->next = node;
//         end = node;
//     }
//     end->next = head;/* ����������β���ָ���  */
//     // head->data = 0;
//     return head;
// }
//
// int main(int argc, char *argv[]) {
//     int x, y;
//     int cnt = -1;
//     LNode* node;
//     Linklist tmp;
//     scanf("%d%d", &x, &y );
//     node = createlist(x);
//     // while(node->next != node){
//     //     cnt++;
//     //     if(cnt == y-2){
//     //         tmp = node->next;
//     //         node->next = tmp->next;
//     //         // free(tmp);
//     //         cnt = -1;
//     //     }
//     //     node = node->next;
//     // }
//     printf("%d\n",node->data );
// 	return 0;
// }
