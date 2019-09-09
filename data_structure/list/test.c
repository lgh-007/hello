/*����Ļ��������÷�*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ���嵥���������� */
typedef struct LNode {
  int data;       /* ���� */
  struct LNode *next;  /* ��һ����ָ���� */
}LNode,*Linklist;
/*���ܣ�����һ������Ϊn������*/
LNode* createlist(int n){
  LNode *head,*node,*end;/* ����ͷ���,��ͨ��㣬β���  */
  int i;
  head = (LNode*)malloc(sizeof(LNode));/* �����ַ  */
  end = head;/* ���ǿ�������ͷβ�ڵ�һ��  */
  for(i = 0; i < n; i++){
    node = (LNode*)malloc(sizeof(LNode));
    scanf("%d",&node->data);
    end->next = node;
    end = node;
  }
  end->next = NULL;/* ����������β���ָ���  */
  head->data = n;
  return head;
}
/*���ܣ�����ѧ�ţ�����������*/
Linklist create(){
  Linklist head,end,node;
  char ch[20];
  char *p = ch;
  int lenth = 0;
  head = (Linklist)malloc(sizeof(LNode));
  end = head;
  printf("������ѧ�ţ��Կո������2 0 1 9 0 1 0 1\n");
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
/*���ܣ������������ĳ���*/
void print(Linklist a){
  int lenth = 0;
  if(a->next == NULL){
    printf("����Ϊ��\n");
    return;
  }
  while(a->next!=NULL) {
    a = a->next;
    lenth++;
    printf("%d ", a->data);
  }
  printf("\n");
}
/*���ܣ��������ĵ�n��Ԫ��*/
void print_n(Linklist a,int n){
  int lenth = 0;
  if(a->data<n||n<1){
		printf("���棡������%dλ�õ�Ԫ��\n",n);
    return ;
  }
  while(a->next!=NULL) {
    a = a->next;
    lenth++;
    if(lenth == n){
      printf("��%d��Ԫ��Ϊ��%d\n",n, a->data);
      break;
    }
  }
}
/*���ܣ��������Ԫ��Ϊn��λ��*/
void print_pos(Linklist a,int n){
  int lenth = 0;
  while(a->next!=NULL) {
    a = a->next;
    lenth++;
    if(a->data == n){
      printf("Ԫ��%d��λ��Ϊ��%d\n",n,lenth);
      break;
    }
  }
}
/*���ܣ��ڵ�4��Ԫ��λ���ϲ���9Ԫ��*/
void insert(Linklist node,int pos,int val){
  Linklist mem,head;/* ����Ҫ����Ľ�� */
  int lenth = 0;
  if(node->data<pos-1||pos<1){
    printf("���棡������%dλ�õ�Ԫ��\n",pos);
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
/*���ܣ�ɾ����pos��Ԫ��*/
void delete(Linklist node,int pos){
  int lenth = 0;
  Linklist tmp,head;
  printf("deleteǰ�ĳ���%d\n",node->data);
  if(node->data<pos||pos<1){
    printf("���棡������%dλ�õ�Ԫ��\n",pos);
    return ;
  }
  head = node;
  while(node->next != NULL) {

    if(lenth == pos-1){
      tmp = node->next;//tmpָ�������Ԫ��
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
