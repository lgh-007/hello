#include <stdio.h>
#include <stdlib.h>
/*栈的基础操作用法*/
#define datasize 400
#define true     1
#define false    0
typedef char Elemtype;
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
/* 判断优先级 */
int  GetPrioirty(char tmp){
  int priority= 0;
  switch (tmp) {
    case '+':priority = 1;break;
    case '-':priority = 1;break;
    case '*':priority = 2;break;
    case '/':priority = 2;break;
    case '(':priority = 3;break;
    case ')':priority = 4;break;
    default: break;
  }
  return priority;
}
/* 主函数 */
int main(int argc, char const *argv[]){
  SqStack mark;
  int cmp_a,cmp_b;
  char val,a,b,c,d;

  InitStack(&mark);
  while(scanf("%c\n", &val)!=EOF){
    a = b = c = 0;
    if(val >='A'&&val<='Z'||val >='a'&&val<='z'){
      printf("%c",val );
    }else{
        cmp_a = GetPrioirty(val);
        if(StackEmpty(&mark)){
          cmp_b = 0;
        }else{
          GetTop(&mark,&b);
          cmp_b = GetPrioirty(b);
        }
        if(cmp_a>cmp_b&&cmp_a<4||cmp_a==3){
            Push(&mark,val);
        }else{
          while(!StackEmpty(&mark)){
            if(cmp_a ==4){
              GetTop(&mark,&b);
              cmp_b = GetPrioirty(b);
              if(cmp_b != 3){
                Pop(&mark,&c);
                printf("%c",c );
              }else{
                Pop(&mark,&d);
                break;
              }
            }else{
              GetTop(&mark,&b);
              cmp_b = GetPrioirty(b);
              if(cmp_a<=cmp_b&&cmp_b != 3){
                Pop(&mark,&c);
                printf("%c",c );
              }else{
                break;
              }
            }
          }
          if(cmp_a<3){
            Push(&mark,val);
          }
        }
    }
  }/*while结束*/
  while(!StackEmpty(&mark)){
    Pop(&mark,&c);
    printf("%c",c);

  }
  return 0;
}
