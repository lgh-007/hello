#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef char ElemType;
//�������Ķ�������ṹ��Ҳ���Ƕ������Ĵ洢�ṹ��1��������2��ָ���򣨷ֱ�ָ�����Һ��ӣ�
typedef  struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
int pindex = 0;
char buff[100];
/*�������Ľ�������ǰ������ķ�ʽ����������*/
void CreateBiTree(BiTree *T){
  if (buff[pindex] == '#'){
    pindex++;
    *T = NULL;  //��֤��Ҷ���
  }else {
      *T = (BiTree)malloc(sizeof(BiTNode));
      //if (!*T)
          //exit(OVERFLOW); //�ڴ����ʧ�����˳���
      (*T)->data = buff[pindex++];//���ɽ��

      CreateBiTree(&(*T)->lchild);//����������
      CreateBiTree(&(*T)->rchild);//����������
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
/*������*/
int main(int argc, char const *argv[]) {
  /* code */
  BiTree t;
  memset(buff,0,100);
  // char *p = arr;
  while(gets(buff)){
    CreateBiTree(&t);
    InOrder(t);
    printf("\n");
    memset(buff,0,100);
    pindex = 0;
  }

  return 0;
}
