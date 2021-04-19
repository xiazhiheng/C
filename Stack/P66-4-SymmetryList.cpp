//判断一个单链表是否是中心对称（使用快慢指针和栈）
#include <iostream>
using namespace std;
#define MaxSize 10

typedef struct Node{
  char data;
  struct Node* next;
}LinkList;
typedef struct{
  char data[MaxSize];
  int top;
}Stack;
void input(LinkList *head);
bool Push(Stack *stack,char c);
char Pop(Stack *stack);
bool Empty(Stack stack);
bool Full(Stack stack);
bool Symmetry(LinkList *head);
int main()
{
    LinkList *head = (LinkList*)malloc(sizeof(LinkList));
    head->next = NULL;
    input(head);
    printf("%d\n",Symmetry(head));
    system("pause");
}
void input(LinkList *head){
  char c;
  LinkList *p = head;
  scanf("%c",&c);
  while(c!= '\n'){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = c;
    node->next = NULL;
    p->next = node; 
    p=p->next;
    scanf("%c",&c);
  }  
}
bool Push(Stack *stack,char c){
  if(Full(*stack)){
    return false;
  }
  stack->data[++stack->top] = c;
  return true;
}
char Pop(Stack *stack){
  if(Empty(*stack)){
    return false;
  }
  return stack->data[stack->top--];
}
bool Empty(Stack stack){
  if(stack.top<0){
    printf("栈空\n");
    return true;
  }
  return false;
}
bool Full(Stack stack){
  if(stack.top>=MaxSize-1){
    printf("栈满\n");
    return true;
  }
  return false;
}
bool Symmetry(LinkList *head){
  LinkList *p = head;
  LinkList *q = head;
  Stack stack;
  stack.top=-1;
  while(q->next!=NULL){
    p = p->next;
    Push(&stack,p->data);
    q = q->next;
    if(q->next==NULL){
      Pop(&stack);
      break;
    }
    q = q->next;
  }
  p=p->next;
  while(p->next!=NULL){
    if(p->data!=Pop(&stack)){
      return false;
    }
    p = p->next;
  }
  return true;
}
