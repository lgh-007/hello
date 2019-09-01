#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
//二叉树的二叉链表结构，也就是二叉树的存储结构，1个数据域，2个指针域（分别指向左右孩子）
typedef  struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
/*二叉树的建立，按前序遍历的方式建立二叉树*/
void CreateBiTree(BiTree *T,char *p){
  // ElemType ch;
  // scanf("%c",&ch);
  if(*p == '\0'){
    return;
  }
  if (*p == '#')
      *T = NULL;  //保证是叶结点
  else
  {
      *T = (BiTree)malloc(sizeof(BiTNode));
      //if (!*T)
          //exit(OVERFLOW); //内存分配失败则退出。
      (*T)->data = *p;//生成结点

      CreateBiTree(&(*T)->lchild,++p);//构造左子树
      CreateBiTree(&(*T)->rchild,++p);//构造右子树
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

int main(int argc, char const *argv[]) {
  /* code */
  BiTree t;
  char arr[100];
  char *p = arr;
  while(gets(arr)){
    CreateBiTree(&t,p);
    printf("%s\n",p);
    InOrder(t);
    printf("\n");
  }


  return 0;
}
