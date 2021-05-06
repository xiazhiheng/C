#include <iostream>
#define MaxSize 10
using namespace std;
typedef struct{
  char *data;
  int lenth;
}String;
int *Next(String str);
int Match(String str1,String str2,int *next);
int main()
{
    String str1;
    str1.data = "aaaaaaba";
    str1.lenth = 8;
    String str2;
    str2.data = "aaaba";
    str2.lenth = 5;
    int *next = Next(str2);
    printf("%d\n",Match(str1,str2,next));
    system("pause");
}
int *Next(String str){
  int *next = (int*)malloc(sizeof(int)*str.lenth);
  next[0] = -1;
  int i=0;
  int j=-1;
  while(i<str.lenth-1){
    if(j==-1 || str.data[i]==str.data[j]){
      ++i;
      ++j;
      next[i] = j;
    }
    else{
      j = next[j];
    }
  }
  return next;
}
int Match(String str1,String str2,int *next){
  int i=0;
  int j=0;
  while(i<str1.lenth){
    if(j==str2.lenth){
      break;
    }
    if(j==-1 || str1.data[i]==str2.data[j]){
      i++;
      j++;
    }else{
      j=next[j];
    }

  }
  if(j==str2.lenth){
    return i-str2.lenth+1;
  }
  return 0;
}
