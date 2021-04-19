#include<iostream>
using namespace std;
int reverse(int x);
int main(){
    printf("%d\n",reverse(-123));
    system("pause");
}
int reverse(int x){
  int Max;
  int y = 0;
  int n = 0;
  int flag;
  if(x<0){
    flag = -1;
    x=-x;
    Max = 8;
  }else{
    flag = 1;
    Max = 7;
  }
  printf("%d\n",x);
  while(x!=0){
    n = x%10;
    x = x/10;
    if(y>214748364){
      return 0;
    }else if(y==214748364 && n>Max){
      return 0;
    }
    y=y*10+n;
  }
  return y*flag;
}