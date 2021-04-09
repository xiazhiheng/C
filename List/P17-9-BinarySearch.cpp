#include<iostream>
using namespace std;
#define MaxSize 20
typedef struct{
  int data[MaxSize];
  int size;
}SqList;
bool Init(SqList *list);
bool Add(SqList *list,int data);
int Binary(SqList list,int n);
int main(){
  SqList list;
  Init(&list);
  int n = 0;
  scanf("%d",&n);
  while(n!=-1){
    Add(&list,n);
    scanf("%d",&n);
  }
  scanf("%d",&n);
  int target = Binary(list,n);
  if(list.data[target]==n){
    if(target<list.size-1){
      list.data[target] = list.data[target+1];
      list.data[target+1] = n;
    }
  }else{
    for(int i=list.size;i>target;i--){
      list.data[i] = list.data[i-1];
    }
    list.data[target] = n;
    list.size++;
  }
  for(int i=0;i<list.size;i++){
    printf("%d ",list.data[i]);
  }
  system("pause");
}
bool Init(SqList *list){
  list->size = 0;
  return true;
}
bool Add(SqList *list,int data){
  list->data[list->size++] = data;
  return true;
}
int Binary(SqList list,int n){
  int right,left,mid;
  left = 0;
  right = list.size-1;
  mid = list.size/2;
  while(right>=left){
    if(list.data[mid]==n){
      return mid;
    }else if(list.data[mid]>n){
      right = mid-1;
    }else{
      left = mid+1;
    }
    mid = left+(right-left)/2;
    // printf("left=%d,right=%d,mid=%d\n",left,right,mid);
  }
  return mid;
}