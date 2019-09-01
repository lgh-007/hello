#include <stdio.h>
#include <stdlib.h>
/*栈的基础操作用法*/
#define datasize 50
#define true     1
#define false    0
typedef int Elemtype;
typedef int bool;

 typedef struct{
   Elemtype data[datasize];
   int top;/* 栈顶指针 */
 }SqStack;
/* 初始化栈 */
void InitStack(SqStack *s){
  s->top = -1;
}
/* 判断栈空 */
bool StackEmpty(SqStack *s){
  if(s->top == -1){
    return true;
  }else{
    return false;
  }
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
/* 读栈顶元素 */
bool GetTop(SqStack *s,Elemtype *x){
  if(s->top == -1){/* 空栈 */
    return false;
  }else{
    *x = s->data[s->top];
  }
  return true;
}


int main(int argc, char const *argv[]){
  SqStack s;
  // InitStack(&s);
  int x;
  Push(&s,1);
  GetTop(&s,&x);
  printf("%d\n", x);
  Push(&s,2);
  Push(&s,3);
  GetTop(&s,&x);
  printf("%d\n", x);
  Pop(&s,&x);
  printf("%d\n", x);
  GetTop(&s,&x);
  printf("%d\n", x);
  return 0;
}
