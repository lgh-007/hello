/*链表的基础操作用法*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 定义单链表结点类型 */
typedef struct LNode {
  int data;       /* 数据 */
  struct LNode *next;  /* 后一结点的指针域 */
}LNode,*Linklist;
/*功能：创建一个长度为n的链表*/
LNode* createlist(int n){
  LNode *head,*node,*end;/* 创建头结点,普通结点，尾结点  */
  int i;
  head = (LNode*)malloc(sizeof(LNode));/* 分配地址  */
  end = head;/* 若是空链表则头尾节点一样  */
  for(i = 0; i < n; i++){
    node = (LNode*)malloc(sizeof(LNode));
    scanf("%d",&node->data);
    end->next = node;
    end = node;
  }
  end->next = NULL;/* 结束创建，尾结点指向空  */
  head->data = n;
  return head;
}
/*功能：输入学号，创建成链表*/
Linklist create(){
  Linklist head,end,node;
  char ch[20];
  char *p = ch;
  int lenth = 0;
  head = (Linklist)malloc(sizeof(LNode));
  end = head;
  printf("请输入学号，以空格隔开如2 0 1 9 0 1 0 1\n");
  fgets(p,20,stdin);
  while(*p != '\n'){
    if(*p == ' '){
      p++;
    }
    node = (Linklist)malloc(sizeof(LNode));
    lenth++;
    node->data = *p-'0';
    end->next = node;
    end = node;
    p++;
  }
  head->data = lenth;
  end->next = NULL;
  return head;
}
/*功能：依次输出链表的长度*/
void print(Linklist a){
  int lenth = 0;
  if(a->next == NULL){
    printf("链表为空\n");
    return;
  }
  while(a->next!=NULL) {
    a = a->next;
    lenth++;
    printf("%d ", a->data);
  }
  printf("\n");
}
/*功能：输出链表的第n个元素*/
void print_n(Linklist a,int n){
  int lenth = 0;
  if(a->data<n||n<1){
		printf("警告！不存在%d位置的元素\n",n);
    return ;
  }
  while(a->next!=NULL) {
    a = a->next;
    lenth++;
    if(lenth == n){
      printf("第%d个元素为：%d\n",n, a->data);
      break;
    }
  }
}
/*功能：输出链表元素为n的位置*/
void print_pos(Linklist a,int n){
  int lenth = 0;
  while(a->next!=NULL) {
    a = a->next;
    lenth++;
    if(a->data == n){
      printf("元素%d的位置为：%d\n",n,lenth);
      break;
    }
  }
}
/*功能：在第4个元素位置上插入9元素*/
void insert(Linklist node,int pos,int val){
  Linklist mem,head;/* 创建要插入的结点 */
  int lenth = 0;
  if(node->data<pos-1||pos<1){
    printf("警告！不存在%d位置的元素\n",pos);
    return ;
  }
  head = node;
  mem = (Linklist)malloc(sizeof(LNode));
  mem->data = val;

  if(pos == 1){
    mem->next = node->next;
    node->next = mem;
  }
  while(node->next!=NULL) {
    node = node->next;
    lenth++;
    if(lenth == pos-1){
      mem->next = node->next;
      node->next = mem;
    }
  }

  head->data++;
}
/*功能：删除第pos个元素*/
void delete(Linklist node,int pos){
  int lenth = 0;
  Linklist tmp,head;
  printf("delete前的长度%d\n",node->data);
  if(node->data<pos||pos<1){
    printf("警告！不存在%d位置的元素\n",pos);
    return ;
  }
  head = node;
  while(node->next != NULL) {

    if(lenth == pos-1){
      tmp = node->next;//tmp指向第三个元素
      node->next = tmp->next;
      free(tmp);
      if(node->next == NULL){
        break;
      }
    }
    node = node->next;
    lenth++;
  }
  head->data--;
}


int  main(int argc, char const *argv[]) {

  int a;
  int cnt = 0;
  Linklist l = NULL;
  l = create();
  printf("%d\n",l->data );
  // print(l);
  // print_n(l,4);
  // print_pos(l,9);
  // insert(l,9,9);
  // print(l);
  delete(l,8);
  print(l);


 // printf("%ld\n",sizeof(LNode));
  return 0;
}
