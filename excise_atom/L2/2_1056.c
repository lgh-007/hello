#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
题目要求：
只有一组输入数据，由许多行组成。 每行会有1~3个整数。 每行的第一个整数代表操作类型，
如果是0，意味着输出所有元素; 如果操作类型是1，意味着要向链表中插入1个整数，后面会有
2个整数分别代表插入位置和插入元素；如果操作类型是2，则表示去掉1个整数，后面会有一个
整数代表去除位置。双向链表在起始时是一个空表。 确保链表中的每个元素都不重复，并且所
有操作都是合法的。
输入：
1 1 2
0
1 2 7
0
2 1
0
1 2 4
1 3 5
1 2 6
0
2 3
0
输出：
2
2 7
7
7 6 4 5
7 6 5
*/

/* 定义双向表结点类型 */
typedef struct DulNode{
  int data;/* 数据 */
  struct DulNode *prior;/* 前一结点的指针域 */
  struct DulNode *next;/* 后一结点的指针域 */
}DulNode,*DuLinkList;
/*创建双向链表的头结点*/
DuLinkList create_du(){
  DuLinkList head;
  head = (DuLinkList)malloc(sizeof(DulNode));
  head->prior = NULL;
  head->next = NULL;
  head->data = 0;
  return head;
}
/*功能：在第pos个元素位置上插入val元素*/
void insert(DuLinkList node,int pos,int val){
  DuLinkList mem,head;
  int lenth = 0;
  // printf("%d\n",node->data);
  if(node->data<pos-1||pos<1){
    printf("警告！不存在%d位置的元素\n",pos);
    return;
  }
  mem = (DuLinkList)malloc(sizeof(DulNode));
  mem->data = val;
  head = node;
  if(pos == 1){/*考虑到第一位置的结点*/
    mem->next = node->next;
    if(node->next!=NULL){/*考虑空链表*/
      node->next->prior = mem;
    }
    node->next = mem;
    mem->prior = node;
    head->data++;
    return;
  }/*if结束*/
  while(node->next!=NULL){
    node = node->next;
    lenth++;
    if(lenth == pos-1){
      mem->next = node->next;
      if(node->next!=NULL){/*考虑最后一个为空*/
        node->next->prior = mem;
      }
      node->next = mem;
      mem->prior = node;
    }
  }/*while结束*/
  if(pos == 4){
    printf("i am here\n");
  }
  head->data++;
  // printf("%d\n",head->data );
}
/*功能：删除第pos个元素*/
void delete(DuLinkList node,int pos){
  DuLinkList tmp,head;
  int lenth = 0;
  if(node->data<pos-1||pos<1){
    printf("警告！不存在%d位置的元素\n",pos);
    return;
  }
  head = node;
  while(node->next!=NULL)
  {
    if(lenth == pos-1){
      tmp = node->next;
      node->next = tmp->next;
      if(node->next!=NULL){/*考虑到最后一个结点*/
        tmp->next->prior = tmp->prior;
      }
      free(tmp);
      if(node->next == NULL){
        break;
      }
    }
    node = node->next;
    lenth++;
  }/*while结束*/
  head->data--;
}
/*功能：依次输出链表的值*/
void print(DuLinkList node){
  if(node->next == NULL){
    printf("链表为空\n");
    return;
  }
  while(node->next!=NULL) {
    node = node->next;
    printf("%d ", node->data);
  }
  printf("\n");
}
/*主函数*/
int main(int argc, char const *argv[]) {
  /* code */
  char p[10] = {0};
  int i = 0;
  DuLinkList l;
  l = create_du();
  while(gets(p)){
    switch (p[0]) {
      case '0':
      print(l);
      break;
      case '1':
      insert(l,p[2]-'0',p[4]-'0');
      break;
      case '2':
      delete(l,p[2]-'0');
      break;
      default:
      break;
    }/* switch结束 */
    memset(p,0,10);
  }/* while结束 */
  return 0;
}
