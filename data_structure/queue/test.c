#include <stdio.h>
#include <stdlib.h>

#define datasize 50
#define true     1
#define false    0
typedef int bool;
typedef int Elemtype;

typedef struct{
  Elemtype data[datasize];
  int front,rear;
}Queue;

void InitQueue(Queue *q){
  q->front = q->rear = 0;
}
bool isEmpty(Queue q){
  if(q.front == q.rear)
    return true;
  else
    return false;
}

bool EnQueue(Queue *q,Elemtype val){
  if((q->rear+1)%datasize == q->front){
    return false;
  }
  q->data[q->rear] = val;
  q->rear = (q->rear+1)%datasize;
  return true;
}

bool DeQueue(Queue *q,Elemtype *val){
  if(q->rear == q->front){
    return false;
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
