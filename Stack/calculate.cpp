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
char* Convert(char *str);
int Cal(char *str);


int main(){
  char* str = (char*)"1+(2*(3+4)/2+5)/6-1wq";
  char* str2 = Convert(str);
  printf("%d\n",Cal(str2)); 
  system("pause");
}

bool InitOpStack(OpStack **stack){
  OpStack *s = (OpStack*)malloc(sizeof(OpStack));
  s->top = -1;
  *stack = s; 
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
  ResStack * s = (ResStack*)malloc(sizeof(ResStack));
  s->top = -1; 
  *stack = s;
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
    return 0;
  case ')':
    return 3;
  default:
    printf("异常运算符\n");
    return 0;
    break;
  }
}
char* Convert(char *str){
  int n = strlen(str);
  char c = str[0];//存储待转换表达式的字符
  char c2 = '\n';//存储出栈的字符,初始化为'\n'
  char *str2 = (char*)malloc(sizeof(char)*(n+1));
  int j = 0;//str2表尾+1的位置
  OpStack *stack;
  InitOpStack(&stack);
  for(int i=0;c!='\0';i++){
    if(c>47){
      str2[j++] = c;
    }else{
      if(c=='('){
        PushOpStack(stack,c);
      }
      else if(c==')'){
        PopOpStack(stack,&c2);
        while(c2!='('){
          str2[j++] = c2;
          PopOpStack(stack,&c2);
        }
        c2 = '\n';//c2恢复初始化
      }else{//运算符
        while(true){
          if(EmptyOpStack(stack)){
            GetOpStack(stack,&c2);
            if(Priority(c)<=Priority(c2)){
              PopOpStack(stack,&c2);
              str2[j++] = c2;
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
    c=str[i];
  }
  while(EmptyOpStack(stack)){
    PopOpStack(stack,&c2);
    str2[j++] = c2; 
  }
  str2[j] = '\0';
  return str2;
}
int Cal(char *str){
  int n = strlen(str);
  int op1;
  int op2;
  char c;//存储字符串取出的字符
  ResStack *stack;
  InitResStack(&stack);
  for(int i=0;i<n;i++){
    c = str[i];
    if(c>47){
      PushResStack(stack,int(c)-48);
    }else{
      PopResStack(stack,&op2);
      PopResStack(stack,&op1);
      switch (c)
      {
      case '+':
        PushResStack(stack,op1+op2);
        break;
      case '-':
        PushResStack(stack,op1-op2);
        break;
      case '*':
        PushResStack(stack,op1*op2);
        break;
      case '/':
        PushResStack(stack,op1/op2);
        break;
      default:
        break;
      }
    }
  }
  PopResStack(stack,&op1);
  return op1;
}