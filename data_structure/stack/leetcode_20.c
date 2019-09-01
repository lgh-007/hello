#include <stdio.h>
#include <stdlib.h>
/*栈的基础操作用法*/
#define datasize 50
#define TRUE     1
#define FALSE    0
typedef char Elemtype;
typedef int bool;

 typedef struct{
   Elemtype data[datasize];
   int top;/* 栈顶指针 */
 }SqStack;
/* 初始化栈 */
void InitStack(SqStack *s){
//  s = (SqStack*)malloc(sizeof(SqStack));
  s->top = -1;
}
/* 判断栈空 */
bool StackEmpty(SqStack *s){
  if(s->top == -1){
    return TRUE;
  }else{
    return FALSE;
  }
}
/* 进栈 */
bool Push(SqStack *s,Elemtype x){
  if(s->top == datasize-1){
    return FALSE;
  }else{
    s->data[++s->top] = x;
  }
  return TRUE;
}
/* 出栈 */
bool Pop(SqStack *s,Elemtype *x){
  if(s->top == -1){/* 空栈 */
    return FALSE;
  }else{
    *x = s->data[s->top--];
  }
  return TRUE;
}
/* 读栈顶元素 */
bool GetTop(SqStack *s,Elemtype *x){
  if(s->top == -1){/* 空栈 */
    return FALSE;
  }else{
    *x = s->data[s->top];
  }
  return TRUE;
}

bool isValid(char* s){
  SqStack q;
  InitStack(&q);
  char tmp;
  int flag = 0;

  while(*s!='\0')
  {
    if(*s == '('||*s == '{'||*s == '['){
      Push(&q,*s);
      s++;
      continue;
    }
    if(*s == ')'){
      GetTop(&q,&tmp);
      if(tmp == '(')Pop(&q,&tmp);
      else return FALSE;
    }else if(*s == '}'){
      GetTop(&q,&tmp);
      if(tmp == '{')Pop(&q,&tmp);
      else return FALSE;
    }else{
      GetTop(&q,&tmp);
      if(tmp == '[')Pop(&q,&tmp);
      else return FALSE;
    }
    s++;
  }
  if(StackEmpty(&q)){
    return TRUE;
  }
  return FALSE;
}

int main(int argc, char const *argv[]){
  char *p;
  SqStack ab;
  InitStack(&ab);
  int a;
  char data[50];
  p = data;
  while(gets(data)){
    a = isValid(p);
    printf("%d\n",a);
  }
  return 0;
}
