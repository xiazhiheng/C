//只增不减的队列
#include<iostream>
using namespace std;
typedef struct Node{
  int data;
  struct Node *next;
}LinkList;
bool EnQue(LinkList **head,LinkList **rear,int n);
bool DelQue(LinkList **head,LinkList *rear,int *n);

int main()
{
    LinkList *head = (LinkList*)malloc(sizeof(LinkList));
    head->next = head;
    LinkList *rear = head;
    int n;
    int a;
    scanf("%d",&n);
    while(n!=-1){
      switch (n)
      {
      case 1:
        scanf("%d",&a);
        EnQue(&head,&rear,a);
        break;
      case 2:
        DelQue(&head,rear,&a);
        break;
      default:
        break;
      }
      scanf("%d",&n);
    }
    system("pause");
}
bool EnQue(LinkList **head,LinkList **rear,int n){
  LinkList *p = *head;
  LinkList *q = *rear;
  if(q->next!=p){
    printf("%d入队1\n",n);
    *rear = q->next;
    q = q->next;
    q->data = n;
  }else{
    printf("%d入队2\n",n);
    struct Node *node = (LinkList*)malloc(sizeof(LinkList));
    node->next = p;
    node->data = n;
    q->next = node;
    *rear = node;
  }
  return true;
}
bool DelQue(LinkList **head,LinkList *rear,int *n){
  LinkList *p = *head;
  if(p==rear){
    printf("队列为空\n");
    return false;
  }
  *n = p->next->data;
  printf("%d出队\n",*n);
  *head = p->next;
  return true;
}
