#include<iostream>
using namespace std;
typedef struct Node{
  int data;
  struct Node *next;
}LinkList;
void input(LinkList *head);
void IncreaseOutput(LinkList *head);//递增输出链表元素，并释放输出节点
int main(){
  LinkList *head = (LinkList*)malloc(sizeof(LinkList));
  input(head);
  IncreaseOutput(head);
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
void IncreaseOutput(LinkList *head){
  LinkList *p = head;
  LinkList *min;
  while(head->next!=NULL){
    p = head;
    min = p;
    while(p->next!=NULL){
      if(min->next->data>p->next->data){
        min = p;
      }
      p=p->next;
    }
    printf("%d ",min->next->data);
    p = min->next;
    min->next = p->next;
    free(p);
  }
}