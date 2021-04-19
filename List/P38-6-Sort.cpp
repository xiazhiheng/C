//链表的排序（*插入排序）
#include<iostream>
using namespace std;
typedef struct Node{
  int data;
  struct Node* next;
}LinkList;
void input(LinkList *head);
void SortInsert(LinkList *head);
void print(LinkList *head);
int main(){
  LinkList *head = (LinkList*)malloc(sizeof(LinkList));
  head->next=NULL;
  input(head);
  SortInsert(head);
  print(head);
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
void SortInsert(LinkList *head){
  LinkList *p;
  LinkList *q = head->next;
  LinkList *node = q->next;
  //将链表变为只含有一个元素的链表，防止元素后继指针指向自己
  q->next = NULL;
  q = node;

  while(q!=NULL){
    node = q->next;
    p = head;
    while(p->next!=NULL && q->data>p->next->data){
      p=p->next;
    }
    q->next = p->next;
    p->next = q;
    q = node;
  }
}
void print(LinkList *head){
  LinkList *p = head->next;
  while(p!=NULL){
    printf("%d ",p->data);
    p=p->next;
  }
  printf("\n");
}