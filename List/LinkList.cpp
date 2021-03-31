#include<iostream>
using namespace std;
#define ElemType int
typedef struct LNode{
  ElemType data;
  struct LNode* next;
}LNode,*LinkList;
bool InitLinkList(LinkList *node);
bool ListInsert(LinkList *node,int loc,ElemType data);
bool ListDelete(LinkList *list,int loc,ElemType *data);
bool Listprint(LinkList list);
int main(){
  LinkList node;
  int n;
  InitLinkList(&node);
  ListInsert(&node,1,10);
  ListInsert(&node,2,20);
  ListInsert(&node,3,30);
  Listprint(node);
  printf("0=%d\n",ListDelete(&node,0,&n));
  printf("1=%d\n",ListDelete(&node,1,&n));
  Listprint(node);
  printf("1=%d\n",ListDelete(&node,2,&n));
  Listprint(node);
  printf("0=%d\n",ListDelete(&node,2,&n));
  printf("1=%d\n",ListDelete(&node,1,&n));
  Listprint(node);
  system("pause");
}
bool InitLinkList(LinkList *node){
  *node = NULL;
  return true;
}
bool ListInsert(LinkList *node,int loc,ElemType data){
  if(loc<1){
    return false;
  }
  if(loc==2 && node==NULL){
    return false;
  }
  LNode *q;
  q = *node;
  int j = 0;

  while(j<loc-2){
    if(q==NULL){
      return false;
    }
    j++;
    q=q->next;
  }
  
  LNode* p = (LNode*)malloc(sizeof(LNode));
  p->data = data;
  p->next = NULL;

  //头插
  if(loc==1){
   p->next = *node;
   *node = p; 
   return true;
  }

  if(q==NULL){
    return false;
  }
  q->next = p;
  return true;
}
bool ListDelete(LinkList *list,int loc,ElemType *data){
  if(loc<1){
    return false;
  }
  LNode *p;
  p = *list;
  int j=1;
  while(p!=NULL && j<loc-1){
    p=p->next;
    j++;
  }
  if(p==NULL){
    return false;
  }
  if(loc == 1){
    *list = p->next;
    free(p);
    return true;
  }
  if(p->next==NULL){
    return false;
  }
  LNode *q;
  q = p->next;
  if(q==NULL){
    p->next = NULL;
    free(q);
    return true;
  }
  p->next = q->next;
  free(q);
  return true;
}
bool Listprint(LinkList list){
  while(list!=NULL){
    printf("%d ",list->data);
    list = list->next;
  }
  printf("\n");
  return true;
}