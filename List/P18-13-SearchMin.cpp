#include<iostream>
using namespace std;
int SearchMin(int num[],int n);//返回所给数组中未出现的最小正整数。
int main(){
  int num[] = {1,2,3,4,5,6,7,-9,-10};
  printf("%d\n",SearchMin(num,7));
  system("pause");
}
int SearchMin(int num[],int n){
  int B[n]={0};
  for(int i=0;i<n;i++){
    if(num[i]<=n && num[i]>0){
      B[num[i]-1] = 1;
    }
  }
  for(int i=0;i<n;i++){
    if(B[i]==0){
      return i+1;
    }
  }
  return n+1;
}