#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char ElemType;
#define datasize 50
#define length   27
//�������Ķ�������ṹ��Ҳ���Ƕ������Ĵ洢�ṹ��1��������2��ָ���򣨷ֱ�ָ�����Һ��ӣ�
typedef  struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

char pre[length];
char in[length];

/*�������*/
void PostOrder(BiTree t){
  if(t){
    PostOrder(t->lchild);
    PostOrder(t->rchild);
	printf("%c",t->data);
  }
}
/*����ǰ��ͺ��򴴽�������*/
void build_tree(BiTree *t, int preL,int preR,int inoL,int inoR)
{
    if(preL > preR) return;
    int e = pre[preL];
    int root = inoL;
    while(in[root] !=e && root <= inoR) ++root;
    *t = (BiTree)malloc(sizeof(BiTNode));
    (*t)->lchild=NULL;
    (*t)->rchild=NULL;
    (*t)->data=e;

    build_tree(&(*t)->lchild,preL+1,preL+root-inoL,inoL,root-1 );
    build_tree(&(*t)->rchild,preL+root-inoL+1,preR,root+1,inoR);

}
/*������*/
int main(int argc, char const *argv[]){

	BiTree t;
    int pre_len, in_len;

    while(gets(pre)){
        gets(in);
        pre_len = strlen(pre) -1;
        in_len = strlen(in) - 1;
        build_tree(&t,0,pre_len,0,in_len);
        PostOrder(t);
        printf("\n");
    }
  return 0;
}
