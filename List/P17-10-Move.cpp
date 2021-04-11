#include<iostream>
using namespace std;
void Reverse(int *S,int h,int f);
int main(){
  int S[]={1,2,3,4,5,6,7,8};
  Reverse(S,0,1);
  Reverse(S,2,7);
  Reverse(S,0,7);
  for(int i=0;i<8;i++){
    printf("%d ",S[i]);
  }
  system("pause");
}
void Reverse(int *S,int h,int f){
  int p;
  while(h<f){
    p=S[h];
    S[h++]=S[f];
    S[f--] = p;
  }
}