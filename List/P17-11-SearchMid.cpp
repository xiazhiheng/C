#include<iostream>
using namespace std;
int SearchMid(int *S1,int *S2,int n);//寻找两个数组的中位数（第n小的数）
int main(){
  int S1[] = {1,2,3,4,5,6,7,10};
  int S2[] = {9,9,10,11,12,13,14,15};
  printf("%d\n",SearchMid(S1,S2,8));
  system("pause");
}
int SearchMid(int *S1,int *S2,int n){
  int s1,m1,d1,s2,m2,d2;
  s1 = 0;
  d1 = n-1;
  s2 = 0;
  d2 = n-1;
  while(s1!=d1 && s2!=d2){
    m1 = (s1+d1)/2;
    m2 = (s2+d2)/2;
    if(S1[m1]==S2[m2]){//中位数相等
      return S1[m1];
    }
    else if(S1[m1]<S2[m2]){
      if((s1+d1)%2==0){//长度为奇数
        s1 = m1;
        d2 = m2;
      }else{
        s1 = m1+1;
        d2 = m2;
      }
    }
    if(S1[m1]>S2[m2]){
      if((s1+d1)%2==0){//长度为奇数
        d1 = m1;
        s2 = m2;
      }else{
        d1 = m1;
        s2 = m2 + 1;
      }
    }
  }
  return S1[s1]>S2[s2] ? S2[s2] : S1[s1]; 
}