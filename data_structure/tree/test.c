#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef char ElemType;
#define datasize 50
//�������Ķ�������ṹ��Ҳ���Ƕ������Ĵ洢�ṹ��1��������2��ָ���򣨷ֱ�ָ�����Һ��ӣ�
typedef  struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef BiTree Elemtype;

typedef struct SqStack{
  Elemtype data[datasize];
  int top;/* ջ��ָ�� */
}SqStack;

void InitStack(SqStack *s){
  s->top = -1;
}
/* ��ջ */
bool Push(SqStack *s,Elemtype x){
  if(s->top == datasize-1){
    return false;
  }else{
    s->data[++s->top] = x;
  }
  return true;
}
/* ��ջ */
bool Pop(SqStack *s,Elemtype *x){
  if(s->top == -1){/* ��ջ */
    return false;
  }else{
    *x = s->data[s->top--];
  }
  return true;
}
/* �ж�ջ�� */
bool StackEmpty(SqStack *s){
  if(s->top == -1){
    return true;
  }else{
    return false;
  }
}
/* ǰ�����������ýڵ㣬Ȼ�����ӣ�����Һ��� */
void PreOrder(BiTree t){
  if(t){
    printf("%c ",t->data);
    PreOrder(t->lchild);
    PreOrder(t->rchild);
  }
}
/* ������� �������ӣ�Ȼ������ý�㣬����Һ���*/
void InOrder(BiTree t){
  if(t){
    InOrder(t->lchild);
    printf("%c ",t->data);
    InOrder(t->rchild);
  }
}
/* ������� �ǵݹ鷽��*/
void InOrder2(BiTree t){
  SqStack s;
  InitStack(&s);
  BiTree p = t;
  while(p||!StackEmpty(&s)){
    if(p){
      Push(&s,p);
      p = p->lchild;
    }else{
      Pop(&s,&p);
      printf("%c ",p->data);
      p = p->rchild;
    }
  }
}
//�������Ľ�������ǰ������ķ�ʽ��������������ȻҲ��������������ķ�ʽ����������
void CreateBiTree(BiTree *T){
    /*Ϊʲô��Ҫ����ָ�룬�������
    �㶨��һ������  a  ��Ҫ�ı�����ֵ����Ҫ�����Ӧ��ָ�룬
    ��������������Ҫ�ı�һ��ָ���ֵ�������Ҫ����ָ������ĵ�ַ�����޸Ķ�Ӧ��ֵ��
    */

    ElemType ch;
    scanf("%c",&ch);
    if (ch == ' ')
        *T = NULL;  //��֤��Ҷ���
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        //if (!*T)
            //exit(OVERFLOW); //�ڴ����ʧ�����˳���
        (*T)->data = ch;//���ɽ��
        CreateBiTree(&(*T)->lchild);//����������
        CreateBiTree(&(*T)->rchild);//����������
    }
}


int main(int argc, char const *argv[]){

	BiTree t;
	CreateBiTree1(t);
	PreOrder(t);
  printf("\n");
  InOrder2(t);
  printf("\n");
  InOrder2(t);
  printf("\n");
  // printf("\n");
  return 0;
}
