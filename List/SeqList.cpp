#include<iostream>
using namespace std;
#define InitSize 10
SeqList* InitList(SeqList *seqList);
SeqList* IncreaseSize(SeqList *seqList,int length);
typedef struct{
  int* data;
  int MaxSize;
  int length; 
}SeqList;
int main(){

}
SeqList* InitList(SeqList *seqList){
  seqList = (SeqList*)malloc(sizeof(SeqList)*InitSize);
  seqList->length = 0;
  seqList->MaxSize = InitSize;
  return seqList;
}
SeqList* IncreaseSize(SeqList *seqList,int length){
  SeqList* seqList2 = (SeqList*)malloc(sizeof(SeqList)*(seqList->MaxSize+length));
  for(int i=0;i<seqList->length;){
    seqList2[i] = seqList[i];
  }
  seqList2->length = seqList->length;
  seqList2->MaxSize = seqList->MaxSize + length;//最大长度增加
  free(seqList);
  return seqList2;
}

