#include <stdio.h>
#include <stdlib.h>
/*
题目要求：
(运算符 参数...)，其中参数为一个或者多个，可以是数字或者表达式，
参数和运算符之间，以及多个参数之间用分隔符（空格）隔开，例如(+ 3 3)、
就是一个合法的表达式，求值结果是6，(* (* 2 3)(^ 4))也是一个合法的
表达式，求值结果是30， 而((+ 5 7)是非法表达式
输入：
(^ (^ (^ (* 1 1))))
(+ (+ 9 18) (^ 1))()
(* (+ 10 10) (^ 2))
输出：
4
29
60
情况  2 + 3   2 3  + 都没有处理
*/
/*栈的基础操作用法*/
#define datasize 100
#define true     1
#define false    0
typedef int Elemtype;
typedef int  bool;
// printf("i am here");
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
/* 主函数 */
int main(int argc, char const *argv[]){
  SqStack val;/* 存放数值的栈 */
  SqStack mark;/* 存放符号的栈 */
  char str[100];/*存放输入 */
  int a,b,c,d,flag,tmp ,result;
  char *p;

  while(gets(str)){
    /*变量初始化 */
    result = 0,flag = 0;
    a = 0,b = 0,c = 0,d = 0;
    p = str;
    InitStack(&val);
    InitStack(&mark);
    /*while循环开始 */
    while(*p != '\0'){
      if(flag == 1 ){
        printf("%d\n",-1);
        break;
      }
      if((*p>='0') && (*p<='9')){
        tmp = 0;
        while(*p!=' '&& *p!=')'){
          tmp = tmp*10;
          tmp += *p-'0';
          p++;
          if(*p == '\0')break;
        }
        Push(&val,tmp);
        if(*p == '\0'){
          GetTop(&mark,&c);
          switch (c) {
            case '+':Pop(&val,&a);Pop(&val,&b);result = a+b;
            break;
            case '*':Pop(&val,&a);Pop(&val,&b);result = a*b;
            break;
            case '^':Pop(&val,&a);result = ++a;
            break;
            default: flag = 1;break;
          }
          if(mark.top == 0){
            printf("%d\n",result);
            break;
          }
        }/*if*p == '\0'结束 */
        // printf("i am num%d\n",tmp);
      }else{
        if(*p!=' '){
          if(*p == ')'){
            Pop(&mark,&c);
            switch (c) {
              case '+':Pop(&val,&a);Pop(&val,&b);result = a+b;
              break;
              case '*':Pop(&val,&a);Pop(&val,&b);result = a*b;
              break;
              case '^':Pop(&val,&a);result = ++a;
              break;
              default: flag = 1;break;
            }
            if(flag == 0){
              if(mark.top == 0){
                printf("%d\n",result);
                break;
              }else{
                Push(&val,result);
                Pop(&mark,&d);
              }
            }
          }else{
            tmp = *p;
            Push(&mark,tmp);
          }
        }
        p++;
        if(*p == '\0'){
          printf("%d\n",-1 );
        }
      }/*else结束*/
    }/*while  *p！= '\0'结束*/
    if(flag == 1||mark.top!=0){
      printf("%d\n",-1 );
    }
  }/*while gets结束*/
  return 0;
}
