#include <iostream>

using namespace std;
typedef struct Node{
  int data;
  struct Node* next;
}LinkList;
void input(LinkList *head);
LinkList* splitList(LinkList *head);
int main()
{
    LinkList *head = (LinkList*)malloc(sizeof(LinkList));
    head->next = NULL;
    input(head);
    splitList(head);
    system("pause");
}
void input(LinkList *head){
  int n;
  LinkList *p = head;
  scanf("%d",&n);
  while(n!=-1){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = n;
    node->next = NULL;
    p->next = node; 
    p=p->next;
    scanf("%d",&n);
  }  
}
LinkList* splitList(LinkList *head){
  LinkList *p;//当前操作节点
  LinkList *r;//an的尾节点
  LinkList *q;//当前节点的下一个节点
  LinkList *head2 = (LinkList*)malloc(sizeof(LinkList));//bn的头结点
  head2->next = NULL;
  r = head;
  p = head->next;
  q = p->next;
  while(true){
    //an尾插
    r->next = p;
    r = p;

    p = q;
    q = p->next;
    //bn头插
    p->next = head2->next;
    head2->next = p;

    if(!q){
      break;
    }
    p = q;
    q = p->next;
  }
  r->next=NULL;
  return head2;
}
