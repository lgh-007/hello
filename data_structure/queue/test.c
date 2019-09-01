#include <stdio.h>
#include <stdlib.h>
/*队列的基础操作用法，循环队列*/

#define datasize 50
#define true     1
#define false    0
typedef int bool;
typedef int Elemtype;

typedef struct{
  Elemtype data[datasize];
  int front,rear;
}Queue;
/* 初始化队列 */
void InitQueue(Queue *q){
  q->front = q->rear = 0;
}
bool isEmpty(Queue q){
  if(q.front == q.rear)
    return true;
  else
    return false;
}
/* 入队 */
bool EnQueue(Queue *q,Elemtype val){
  if((q->rear+1)%datasize == q->front){
    return false;/* 队列满 */
  }
  q->data[q->rear] = val;
  q->rear = (q->rear+1)%datasize;
  return true;
}
/* 出队 */
bool DeQueue(Queue *q,Elemtype *val){
  if(q->rear == q->front){
    return false;/* 队空 */
  }
  *val = q->data[q->front];
  q->front = (q->front+1)%datasize;
  return true;
}

int main(int argc, char const *argv[]){

  Queue q;
  int val;
  InitQueue(&q);
  EnQueue(&q,1);
  EnQueue(&q,2);
  EnQueue(&q,3);
  DeQueue(&q,&val);
  printf("%d\n",val);
  DeQueue(&q,&val);
  printf("%d\n",val);
  DeQueue(&q,&val);
  printf("%d\n",val);
  if(!DeQueue(&q,&val)){
    printf("is full\n");
  }

  return 0;
}
