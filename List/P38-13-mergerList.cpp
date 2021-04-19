#include <iostream>

using namespace std;
typedef struct Node{
  int data;
  struct Node* next;
}LinkList;
void input(LinkList *head);
LinkList *merger(LinkList* head1,LinkList* head2);
int main()
{
    LinkList *head1 = (LinkList*)malloc(sizeof(LinkList));
    head1->next==NULL;
    LinkList *head2 = (LinkList*)malloc(sizeof(LinkList));
    head2->next==NULL;
    input(head1);
    input(head2);
    merger(head1,head2);
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
LinkList *merger(LinkList* head1,LinkList* head2){
  LinkList *p1;
  LinkList *p2;
  LinkList *q;//工具人节点
  p1 = head1->next;
  p2 = head2->next;
  head1->next = NULL;

  // while(p1 || p2){
  //   if(!p1){
  //     q = p2->next;
  //     p2->next = head1->next;
  //     head1->next = p2;
  //     p2 = q;
  //   }else if(!p2){
  //     q = p1->next;
  //     p1->next = head1->next;
  //     head1->next = p1;
  //     p1 = q;
  //   }else if(p1->data<p2->data){
  //     q = p1->next;
  //     p1->next = head1->next;
  //     head1->next = p1;
  //     p1 = q;
  //   }else{
  //      q = p2->next;
  //     p2->next = head1->next;
  //     head1->next = p2;
  //     p2 = q;
  //   }
  // }

  //优化后
  while(p1&&p2){
    if(p1->data<p2->data){
      q = p1->next;
      p1->next = head1->next;
      head1->next = p1;
      p1 = q;
    }else{
      q = p2->next;
      p2->next = head1->next;
      head1->next = p2;
      p2 = q;
    }
  }
  if(p1){
    p2 = p1;
  }
  while(p2){
    q = p2->next;
    p2->next = head1->next;
    head1->next = p2;
    p2 = q;
  }
  
return head1;
}