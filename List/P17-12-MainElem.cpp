#include<iostream>
using namespace std;
int MainElem(int num[],int n);
int main(){
  int num[] = {1,1,2,3,4,1,4,1,1,1,6};
  printf("%d\n",MainElem(num,5));
  system("pause");
}
int MainElem(int num[],int n){
  int c = num[0];
  int count = 1;
  for(int i=1;i<n;i++)
    if(num[i]==c)
      count++;
    else
      if(count>0)
        count--;
      else{
        c = num[i];
        count = 1;
      }
  count=0;
  for(int i=0;i<n;i++)
    if(num[i]==c)
      count++;
  if(count>n/2)
    return c;
  return -1;
}