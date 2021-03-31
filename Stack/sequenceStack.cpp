#include<iostream>
using namespace std;
#define MaxSize 3
#define ElmeType int

typedef struct{
  ElmeType data[MaxSize];
  int top;//栈顶指针
}SqStack;
bool Push(SqStack *stack,ElmeType data);
bool Pop(SqStack *stack,ElmeType *data);
bool GetTop(SqStack *stack,ElmeType *data);
int main(){
  int n = -1;
  int n1 = 0;
  SqStack* stack = (SqStack *)malloc(sizeof(SqStack));
  stack->top=0;
  while(n!=0){
    printf("1.入栈\n2.出栈\n3.栈顶\n0.退出\n");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
      scanf("%d",&n1);
      if(Push(stack,n1)){
        printf("入栈成功\n");
      }else{
        printf("栈满\n");
      }
      break;
    case 2:
      if(Pop(stack,&n1)){
        printf("n1=%d\n",n1);
      }else{
        printf("栈空\n");
      }
      break;
    case 3:
      if(GetTop(stack,&n1)){
        printf("n1=%d\n",n1);
      }else{
        printf("栈空\n");
      }
      break;
    default:
      break;
    }
  }
}
bool Push(SqStack *stack,ElmeType data){
  if(stack->top == MaxSize){
    return false;
  }
  stack->data[stack->top] = data;
  stack->top++;
  return true;
}
bool Pop(SqStack *stack,ElmeType *data){
  if(stack->top == 0){
    return false;
  }
  *data = stack->data[stack->top-1];
  stack->top--;
  return true;
}
bool GetTop(SqStack *stack,ElmeType *data){
  if(stack->top == 0){
    return false;
  }
  *data = stack->data[stack->top-1];
  return true;
}