#include<iostream>
using namespace std;
#define ElemType int
#define MaxSize 3
typedef struct{
  ElemType data[MaxSize];
  int front,rear;
  // int size;
  // int tag;
}SqQueue;
SqQueue intiQue(SqQueue &que);
bool EnQue(SqQueue &que,ElemType data); 
bool DeQue(SqQueue &que,ElemType *data);
bool GetQue(SqQueue que,ElemType *data);  
int main(){
  SqQueue que;
  int n1;
  intiQue(que);
  EnQue(que,1);
  EnQue(que,2);
  EnQue(que,3);
  EnQue(que,4);
  GetQue(que,&n1);
  printf("%d\n",n1);
  DeQue(que,&n1);
  GetQue(que,&n1);
  printf("%d\n",n1);
  DeQue(que,&n1);
  DeQue(que,&n1);
  GetQue(que,&n1);
  system("pause");
}
SqQueue intiQue(SqQueue &que){
  que.front = 0;
  que.rear = 0;
  return que;
}
bool EnQue(SqQueue &que,ElemType data){
  if((que.rear+1)%MaxSize==que.front){
    printf("队列已满\n");
    return false;
  }
  que.data[que.rear] = data;
  que.rear = (que.rear+1)%MaxSize;
  return true;
}
bool DeQue(SqQueue &que,ElemType *data){
  if(que.rear==que.front){
    printf("队列为空\n");
    return false;
  }
  *data = que.data[que.front];
  que.front = (que.front+1)%MaxSize;
  return true;
}
bool GetQue(SqQueue que,ElemType *data){
  if(que.rear==que.front){
    printf("队列为空2\n");
    return false;
  }
  *data = que.data[que.front];
  return true;
}
