#include <iostream>

using namespace std;

typedef struct ListNode {
      int val;
      struct ListNode *next;
 }LinkList;

void input(LinkList *head);
struct ListNode* reverseList(struct ListNode* head);
int main()
{
    LinkList *head = (LinkList*)malloc(sizeof(LinkList));
    head->next=NULL;
    input(head);
    reverseList(head);
    while(head->next!=NULL){
      printf("%d ",head->next->val);
      head = head->next;
    }
    system("pause");
}
void input(LinkList *head){
  int n;
  LinkList *p = head;
  scanf("%d",&n);
  while(n!=-1){
    LinkList *node = (LinkList*)malloc(sizeof(LinkList));
    node->val = n;
    node->next = NULL;
    p->next = node; 
    p=p->next;
    scanf("%d",&n);
  }  
}
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *p = head->next;
    struct ListNode *q;
    if(head->next == NULL){
        return head;
    }
    q = p;
    p = p->next;
    q->next = NULL;
    while(p != NULL){
        q = p;
        p = p->next; 
        q->next = head->next;
        head->next = q;
    }
    return head;
}
