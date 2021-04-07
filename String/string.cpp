#include<iostream>
using namespace std;
#define MaxSize 10
typedef struct{
  char data[MaxSize];
  int lenth;
}String;
bool SubString(String &Sub,String S,int pos,int len);
int StrCompare(String S,String T);
int Index(String S,String T);
int main(){
  system("pause");
}