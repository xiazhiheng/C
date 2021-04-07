#include<iostream>
using namespace std;
int main(){
  int x;
  int n;
  int no[20];
  int val[20];
  int top = -1;
  int p1 = 2*x;
  int p2 = 1;
  scanf("%d",&x);
  scanf("%d",&n);
  if(n==0){
    printf("%d",p2);
  }
  for(int i=n;i<=2;i--){
    no[++top] = i;
  }
  while (top!=-1){
    val[top] = 2*x*p1-2*(no[top]-1)*p2;
    p1 = val[top--];
    p2 = p1;
  }
  printf("%d",p1);
  system("pause");
}