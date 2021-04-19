//用两个栈来模拟一个队列
#include <iostream>
using namespace std;
#define MaxSize 3
typedef struct{
  char data[MaxSize];
  int top;
}Stack;
bool Pop(Stack *stack,int *n);
bool Push(Stack *stack,int n);
bool StackEmpty(Stack stack);
bool StackOverflow(Stack stack);
bool EnQue(Stack *stack1,Stack *stack2,int n);
bool DeQue(Stack *stack1,Stack *stack2,int *n);
bool QueueEmpty(Stack *stack1,Stack *stack2);
int main()
{
    int n;
    int a;
    Stack stack1;
    stack1.top = -1;
    Stack stack2;
    stack2.top = -1;
    scanf("%d",&n);
    while(n!=0){
      switch(n){
        case 1:
          scanf("%d",&a);
          EnQue(&stack1,&stack2,a);
          break;
        case 2:
          DeQue(&stack1,&stack2,&a);
          break;
        case 3:
          printf("%d\n",QueueEmpty(&stack1,&stack2));
          break;
        default:
          break;
      }
      scanf("%d",&n);
    }
    system("pause");
}
bool Pop(Stack *stack,int *n){
  if(stack->top<0){
    printf("栈空\n");
    return false;
  }
  *n = stack->data[stack->top--];
  return true;
}
bool Push(Stack *stack,int n){
  if(stack->top>=MaxSize-1){
    printf("栈满\n");
    return false;
  }
  stack->data[++stack->top] = n;
  return true;
}
bool StackEmpty(Stack stack){
  if(stack.top<0){
    return true;
  }
  return false;
}
bool StackOverflow(Stack stack){
  if(stack.top>=MaxSize-1){
    return true;
  }
  return false;
}
bool EnQue(Stack *stack1,Stack *stack2,int n){
  if(StackOverflow(*stack1)){
    if(StackEmpty(*stack2)){
      int a;
      while(!StackEmpty(*stack1)){
        Pop(stack1,&a);
        Push(stack2,a);
      }
    }else{
      printf("入队失败\n");
      return false;
    }
  }
  return Push(stack1,n);
}
bool DeQue(Stack *stack1,Stack *stack2,int *n){
  if(StackEmpty(*stack2)){
    if(StackEmpty(*stack1)){
      printf("队列为空\n");
      return false;
    }else{
      int a;
      while(!StackEmpty(*stack1)){
        Pop(stack1,&a);
        Push(stack2,a);
      }
    }
  }
  Pop(stack2,n);
  return true;
}
bool QueueEmpty(Stack *stack1,Stack *stack2){
  if(StackEmpty(*stack1) && StackEmpty(*stack2)){
    return true;
  }
  return false;
}
