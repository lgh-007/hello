#include <stdio.h>
#include <stdlib.h>

// int datasize;
#define true     1
#define false    0
typedef int Elemtype;
typedef int bool;
typedef struct {
    int *data;
    int datasize;
    int front,rear;
} MyCircularQueue;
/* 初始化队列 */
MyCircularQueue* myCircularQueueCreate(int k) {
  MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
  q->data = (int*)malloc(sizeof(int)*(k+1));
  q->datasize = k+1;
  q->rear = q->front = 0;
  return q;
}
/* 进队列 */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
  if((obj->rear+1)%obj->datasize == obj->front)
    return false;
  obj->data[obj->rear] = value;
  obj->rear = (obj->rear+1)%obj->datasize;
    return true;
}
/* 删除队列 头元素 */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
  if(obj->rear == obj->front)
    return false;
  obj->front = (obj->front+1)%obj->datasize;
  return true;
}
/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
  int val;
  if(obj->rear == obj->front)
    return false;
  val = obj->data[obj->front];
  // obj->front = (obj->front+1)%datasize;
  return val;
}
/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
  int val;
  if(obj->rear == obj->front)
    return false;
  val = obj->data[obj->rear-1];
  // obj->front = (obj->front+1)%datasize;
  return val;
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  if(obj->rear == obj->front)
    return true;
  return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
  if((obj->rear+1)%obj->datasize == obj->front)
    return true;
  return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
  free(obj);
}




int main(int argc, char const *argv[]) {
  MyCircularQueue *test;
  test = myCircularQueueCreate(3);
  myCircularQueueEnQueue(test,1);
  myCircularQueueEnQueue(test,2);
  myCircularQueueEnQueue(test,3);
  if(myCircularQueueIsFull)
    printf("i am here\n");
  printf("%d\n", myCircularQueueRear(test));
  return 0;
}
