#include<iostream>
using namespace std;
#define MaxSize 10
typedef struct{
  char data[MaxSize];
  int lenth;
}String;
bool SubString(String *Sub,String S,int pos,int len);
int StrCompare(String S,String T);
int Index(String S,String T);
void print(String S);
int main(){
  system("pause");
}
bool SubString(String *Sub,String S,int pos,int len){
  pos--;
  if(Sub->lenth+len>MaxSize){
    return false;
  } 
  for(int i=0;i<len;i++){
    Sub->data[Sub->lenth++]=S.data[pos++];
  }
  return true;
}
int StrCompare(String S,String T){
  for(int i=0;i<S.lenth && i<T.lenth;i++){
    if(S.data[i]!=T.data[i]){
      return S.data[i]-T.data[i];
    }
  }
  return S.lenth-T.lenth;
}
int Index(String S,String T){
  for(int i=0,j=0;i<=S.lenth-T.lenth;i++){
    j=0;
    for(;j<T.lenth;j++){
      if(S.data[i+j]!=T.data[j]){
        break;
      }
    }
    if(j==T.lenth){
      return i+1;
    }
  }
  return 0;
}
void print(String S){
  for(int i=0;i<S.lenth;i++){
    printf("%c",S.data[i]);
  }
  printf("\n");
}