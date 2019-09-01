#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef char ElemType;
#define datasize 50
//二叉树的二叉链表结构，也就是二叉树的存储结构，1个数据域，2个指针域（分别指向左右孩子）
typedef  struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef BiTree Elemtype;

typedef struct SqStack{
  Elemtype data[datasize];
  int top;/* 栈顶指针 */
}SqStack;

void InitStack(SqStack *s){
  s->top = -1;
}
/* 进栈 */
bool Push(SqStack *s,Elemtype x){
  if(s->top == datasize-1){
    return false;
  }else{
    s->data[++s->top] = x;
  }
  return true;
}
/* 出栈 */
bool Pop(SqStack *s,Elemtype *x){
  if(s->top == -1){/* 空栈 */
    return false;
  }else{
    *x = s->data[s->top--];
  }
  return true;
}
/* 判断栈空 */
bool StackEmpty(SqStack *s){
  if(s->top == -1){
    return true;
  }else{
    return false;
  }
}
/* 前序遍历：输出该节点，然后左孩子，最后右孩子 */
void PreOrder(BiTree t){
  if(t){
    printf("%c ",t->data);
    PreOrder(t->lchild);
    PreOrder(t->rchild);
  }
}
/* 中序遍历 ：先左孩子，然后输出该结点，最后右孩子*/
void InOrder(BiTree t){
  if(t){
    InOrder(t->lchild);
    printf("%c ",t->data);
    InOrder(t->rchild);
  }
}
/* 中序遍历 非递归方法不理解可以画图看下*/
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
/*二叉树的建立，按前序遍历的方式建立二叉树*/
void CreateBiTree(BiTree *T){
    ElemType ch;
    scanf("%c",&ch);
    if (ch == ' ')
        *T = NULL;  //保证是叶结点
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        //if (!*T)
            //exit(OVERFLOW); //内存分配失败则退出。
        (*T)->data = ch;//生成结点
        CreateBiTree(&(*T)->lchild);//构造左子树
        CreateBiTree(&(*T)->rchild);//构造右子树
    }
}

int main(int argc, char const *argv[]){

	BiTree t;
	CreateBiTree(&t);
	PreOrder(t);
  printf("\n");
  InOrder2(t);
  printf("\n");
  InOrder2(t);
  printf("\n");
  // printf("\n");
  return 0;
}
