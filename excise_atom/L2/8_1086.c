#include <stdio.h>
#include <stdlib.h>
//printf("i am here");
#define Error 0
typedef struct OLNode{
  int i,j;/*非零元的行列下标*/
  int val;/*非零元素值*/
  struct OLNode *right,*down;/*改非零元指向所在行列的猴急链域*/
}OLNode,*OLink;

typedef struct{
  OLink *rhead,*chead;/*双重指针，有时候可以看成是数组指针的概念*/
  int mu,nu,tu;/*稀疏矩阵的行数列数和非零元个数*/
}CrossList;
/*建立稀疏矩阵十字链表*/
int CreateSMatrix_OL(CrossList *M){
  // if(M){
  //   free(M);
  // }
  // printf("i am here");
  int m,n,a,b,val;
  OLink  p,q;
  scanf("%d",&m);
  scanf("%d",&n);
  getchar();
  M->mu = m;M->nu = n;
  /*定义数组指针，存放各行各列的头指针。*/
  M->rhead = (OLink*)malloc(sizeof(OLink)*(m+1));
  // if(!M->rhead) return Error;
  M->chead = (OLink*)malloc(sizeof(OLink)*(n+1));
  // if(!M->chead) return Error;
  /*初始化各个行列指针的*/
  for(a = 1;a < m;a++){
    M->rhead[a] = NULL;
  }
  for(b = 1;b < n;b++){
    M->chead[b] = NULL;
  }

  for(a = 1; a <= m;a++){
    for(b = 1;b <= n;b++){
      scanf("%d",&val);
      if(val != 0){/*将各个节点插入*/

        p = (OLink)malloc(sizeof(OLNode));/*定义新节点*/
        // if(p == -1) return Error;
        /*初始化新节点*/
        p->i = a,p->j = b;p->val = val;p->right = NULL,p->down = NULL;
        /*插入行*/
        if(M->rhead[a]==NULL){//||M->rhead[a]->j >b
          //p->right = M.rhead[i];
          M->rhead[a] = p;
          // printf("i am here");
        }else{
          for(q = M->rhead[a];(q->right)&&(q->right->j<b);q = q->right);
          q->right = p;
          // printf("i am there");
        }/*完成行的插入*/
        /*插入列*/
        // if(M->down[b]==NULL){
        //   p->right = M.rhead[i];
        //   M->chead[b] = p;
        // }else{
        //   for(q = M->chead[b];(q->right)&&(q->right->j<b);q = q->right);
        //   q->right = p;
        // }/*完成列的插入*/
      }/*if结束*/
    }/*内部for循环结束*/
    getchar();
  }/*外部for循环结束*/
}
void print(CrossList *M){
  int i,j;
  OLink p;

  for(i = 1;i <= M->mu;i++){
    p = M->rhead[i];
    for(j = 1;j<=M->nu;j++){
      if(p!=NULL&&p->j == j){
        printf("%d ",p->val);
        p = p->right;
      }
      else{
        printf("%d ",0);
      }
    }
    printf("\n");
  }
}
int main(int argc, char const *argv[]) {
  CrossList M;
  CreateSMatrix_OL(&M);
  print(&M);
  return 0;
}
