#include<iostream>
#include<string.h>
using namespace std;
#define MaxSize 10
typedef struct{
  char op[MaxSize];
  int priority[MaxSize];
  int top;
}OpStack;//运算符栈
typedef struct{
  int data[MaxSize];
  int top;
}ResStack;//运算结果栈
bool InitOpStack(OpStack **stack);
bool PushOpStack(OpStack *stack,char data);
bool PopOpStack(OpStack *stack,char *data);
bool GetOpStack(OpStack *stack,char *data);
bool EmptyOpStack(OpStack *stack);
bool InitResStack(ResStack **stack);
bool PushResStack(ResStack *stack,int data);
bool PopResStack(ResStack *stack,int *data);
bool GetResStack(OpStack *stack,char *data);
bool EmptyResStack(OpStack *stack);

int Priority(char c);
void Convert(char *str);

int Cal(char *str);
int main(){
  OpStack *stack;
  InitOpStack(&stack);
}

bool InitOpStack(OpStack **stack){
  OpStack * s = *stack;
  s = (OpStack*)malloc(sizeof(OpStack));
  s->top = -1; 
  return true;
}
bool PushOpStack(OpStack *stack,char data){
  if(stack->top==MaxSize-1){
    printf("栈满\n");
    return false;
  }
  stack->top++;
  stack->op[stack->top] = data;
  stack->priority[stack->top] = Priority(data);
  return true;
}
bool PopOpStack(OpStack *stack,char *data){
  if(stack->top==-1){
    printf("栈空\n");
    return false;
  }
  *data = stack->op[stack->top];
  stack->top--;
  return true;
}
bool GetOpStack(OpStack *stack,char *data){
  *data = stack->op[stack->top];
  return true;
}
bool EmptyOpStack(OpStack *stack){
  if(stack->top==-1){
    return false;
  }
  return true;
}
bool InitResStack(ResStack **stack){
  ResStack * s = *stack;
  s = (ResStack*)malloc(sizeof(ResStack));
  s->top = -1; 
  return true;
}
bool PushResStack(ResStack *stack,int data){
  if(stack->top==MaxSize-1){
    printf("栈满\n");
    return false;
  }
  stack->top++;
  stack->data[stack->top] = data;
  return true; 
}
bool PopResStack(ResStack *stack,int *data){
  if(stack->top==-1){
    printf("栈空\n");
    return false;
  }
  *data = stack->data[stack->top];
  stack->top--;
  return true;
}
bool GetResStack(OpStack *stack,char *data){
  *data = stack->op[stack->top];
  return true;
}
bool EmptyResStack(OpStack *stack){
  if(stack->top==-1){
    return false;
  }
  return true;
}
int Priority(char c){
  switch (c)
  {
  case '+':
    return 1;
  case '-':
    return 1;
  case '*':
    return 2;
  case '/':
    return 2;
  case '(':
    return 3;
  case ')':
    return 3;
  default:
    printf("异常运算符\n");
    return 0;
    break;
  }
}
void Convert(char *str){
  int n = strlen(str);
  char c = '\n';//存储待转换表达式的字符，初始化为'\n'
  char c2 = '\n';//存储出栈的字符,初始化为'\n'
  char *str2 = (char*)malloc(sizeof(char)*n);
  OpStack *stack;
  InitOpStack(&stack);
  for(int i=0;c!='\0';i++){
    c=str[i];
    if(c>47){//数字,数字大于10问题
      
    }else{
      if(c=='('){
        PushOpStack(stack,c);
      }
      else if(c==')'){
        while(c2!='('){
          PopOpStack(stack,&c2);
          /*实现拼接字符串*/

        }
        c2 = '\n';//c2恢复初始化
      }else{//运算符
        while(true){
          if(EmptyOpStack(stack)){
            GetOpStack(stack,&c2);
            if(Priority(c)<=Priority(c2)){
              PopOpStack(stack,&c2);
              /*实现拼接字符串*/

            }else{
              break;
            }
          }else{
            break;
          }
        }
        PushOpStack(stack,c);
      }
    }
  }
}
int Cal(char *str);