#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*栈的基础操作用法*/
typedef int bool;
#define DATASIZE 50
#define TRUE     1
#define FALSE    0
typedef char Elemtype;


 typedef struct{
   char data[DATASIZE];
   int top;/* 栈顶指针 */
 }SqStack;
/* 初始化栈 */
SqStack* InitStack(){
  SqStack* q;
  // q->data = (char*)malloc(sizeof(char) * (size));
  q = (SqStack*)malloc(sizeof(SqStack));
  q->top = -1;
  return q;
}
/* 判断栈空 */
bool StackEmpty(SqStack *s){
  if(s->top == -1){
    return TRUE;
  }
  return FALSE;
}
/* 进栈 */
bool Push(SqStack *s,Elemtype x){
  if(s->top == DATASIZE-1){
    return TRUE;
  }else{
    s->data[++s->top] = x;
  }
  return FALSE;
}
/* 出栈 */
char Pop(SqStack *s){
  char x;
  if(s->top == -1){/* 空栈 */
    return FALSE;
  }
  x = s->data[s->top];
  s->data[s->top] = '\0';
  s->top--;
  return x;
}
/* 读栈顶元素 */
char GetTop(SqStack *s){
  char x;
  if(s->top == -1){/* 空栈 */
    return FALSE;
  }
  x = s->data[s->top];
  return x;
}

char * simplifyPath(char * path){
  int len = strlen(path);
  SqStack* q;
  char tmp;
  int flag,cnt,i;
  p = malloc(DATASIZE);
  q = InitStack();
  while(*path!='\0'){
    flag = 0;
    cnt = 0;
    if(*path!='/'&&*path!='.'||StackEmpty(q)){
      Push(q,*path);
      path++;
      continue;
    }
    if(*path == '/'){
      if(gettop(q) != '/') {
        if(gettop(q) == '.') Pop(q);
        else Push(q,*path);
      }
    }else{

    }
    path++;
  }

  if(GetTop(q)=='/'&&q->top!=0){
    Pop(q);
    Push(q,'\0');
  }
  for(i = 0;i<=q->top;i++){
    p[i] = q->data[i];
  }
  return p;
}

int main(int argc, char const *argv[]){

  char *p,*q;
  char data[50];
  q = data;
  while(gets(data)){
    p = simplifyPath(q);
    printf("%s\n",p);
  }
  // SqStack s;
  // InitStack(&s);
  // int x;
  // Push(&s,1);
  // GetTop(&s,&x);
  // printf("%d\n", x);
  // Push(&s,2);
  // Push(&s,3);
  // GetTop(&s,&x);
  // printf("%d\n", x);
  // Pop(&s,&x);
  // printf("%d\n", x);
  // GetTop(&s,&x);
  // printf("%d\n", x);
  return 0;
}
