#include<iostream>
using namespace std;
#define ElemType int
typedef struct Node{
  ElemType data;
  struct Node* next;
}LinkNode;
typedef struct{
  LinkNode* front;
  LinkNode* rear;
}LinkQueue;
LinkQueue InitQue(LinkQueue &que);
bool EnQue(LinkQueue &que,ElemType data);
bool DelQue(LinkQueue &que,ElemType *data);
bool GetQue(LinkQueue &que,ElemType *data);
int main(){
  int n1;
  LinkQueue que;
  InitQue(que);
  EnQue(que,1);
  EnQue(que,2);
  EnQue(que,3);
  GetQue(que,&n1);
  printf("%d\n",n1);
  DelQue(que,&n1);
  GetQue(que,&n1);
  printf("%d\n",n1);
  DelQue(que,&n1);
  DelQue(que,&n1);
  DelQue(que,&n1);
  GetQue(que,&n1);
  system("pause");
}
LinkQueue InitQue(LinkQueue &que){
  que.front = NULL;
  que.rear = NULL;
  return que;
}
bool EnQue(LinkQueue &que,ElemType data){
  LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
  node->data = data;
  if(que.front == NULL){
    que.front = node;
    que.rear = node;
    printf("入队成功\n");
    return true;
  }
  que.rear->next = node;
  que.rear = node;
  printf("入队成功\n");
  return true;
}
bool DelQue(LinkQueue &que,ElemType *data){
  if(que.front==NULL){
    printf("队列为空\n");
    return false;
  }
  LinkNode* q;
  q = que.front;
  *data = q->data;
  if(que.front==que.rear){
    que.front=NULL;
  }
  else{
    q = que.front;
    que.front = q->next; 
  }
  free(q);
  printf("出队成功\n");
  return true;
}
bool GetQue(LinkQueue &que,ElemType *data){
   if(que.front==NULL){
    printf("队列为空2\n");
    return false;
  }
  *data = que.front->data;
  return true;
}