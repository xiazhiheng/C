#include <iostream>

using namespace std;
typedef struct Node{
  int data;
  struct Node* pred;
  struct Node* next;
  int freq;
}LinkList;
void input(LinkList *head);
LinkList *Locate(LinkList *head,int x);
int main()
{
    LinkList *head = (LinkList*)malloc(sizeof(LinkList));
    head->next = NULL;
    input(head);
    int n;
    scanf("%d",&n);
    while(n!=-1){
      Locate(head,n);
      scanf("%d",&n);
    }
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
    node->freq = 0;
    node->pred = p;  
    p->next = node; 
    p = p->next;
    scanf("%d",&n);
  }  
}
LinkList *Locate(LinkList *head,int x){
  LinkList *p = head->next;
  LinkList *q;//工具指针
  while(p){
    if(p->data == x){
      p->freq++;
      break;
    }
    p=p->next;
  }
  if(!p){
    return p;
  }

  // if(p->next == NULL){
  //   if(p->pred!=head && p->pred->freq<=p->freq ){
  //     p->pred->next = p->next;
  //     p->pred = p->pred->pred;
  //     // p->next->pred = p->pred->next;
  //     p->next = p->pred->next;
  //     p->pred->next->pred = p;
  //     p->pred->next = p;   
  //   }
  // }
  // while(p->pred!=head && p->pred->freq<=p->freq ){
  //   p->pred->next = p->next;
  //   p->pred = p->pred->pred;

  //   p->next->pred = p->pred->next;

  //   p->next = p->pred->next;
  //   p->pred->next->pred = p;
  //   p->pred->next = p;   
  // }

  if(p->freq<p->pred->freq){
    return p;
  }

  //优化
  if(p->next != NULL){
    p->next->pred = p->pred;
  }
  p->pred->next = p->next;
  q = p->pred;
  while(q!=head && p->freq>=q->freq){
    q = q->pred;
  }
  p->next = q->next;
  q->next->pred=p;
  p->pred = q;
  q->next = p;
  return p;
}