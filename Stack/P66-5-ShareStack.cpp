//共享栈
#include <iostream>
using namespace std;
#define MaxSize 5
typedef struct{
  int data[MaxSize];
  int top[2];
}Stack;
void Init(Stack *stack);
bool Push(Stack *stack,int top,int n);
bool Pop(Stack *stack,int top,int *n);
int main()
{
    int n;
    Stack stack;
    Init(&stack);
    Push(&stack,0,1);
    Push(&stack,1,2);
    Pop(&stack,0,&n);
    Pop(&stack,1,&n);
    Pop(&stack,0,&n);
    Pop(&stack,1,&n);

    system("pause");
}
void Init(Stack *stack){
  stack->top[0] = -1;
  stack->top[1] = MaxSize;
}
bool Push(Stack *stack,int top,int n){
  if(stack->top[1] == stack->top[0]+1){
    printf("栈满\n");
    return false;
  }
  if(top == 0){
    stack->data[++stack->top[0]] = n;
  }else{
    stack->data[--stack->top[1]] = n;
  }
  return true;
}
bool Pop(Stack *stack,int top,int *n){
  if(top==0){
    if(stack->top[0]<0){
      printf("栈空\n");
      return false;
    }
    *n = stack->data[stack->top[0]--];
  }else{
    if(stack->top[1]>=MaxSize){
      printf("栈空\n");
      return false;
    }
    *n = stack->data[stack->top[1]++];
  }
  return true;
}
