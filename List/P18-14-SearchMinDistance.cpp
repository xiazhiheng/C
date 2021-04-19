//a={S1},b={S1},c={S3}，|a-b|+|b-c|+|c-a|的最小值
#include<iostream>
#include<stdlib.h>
using namespace std;
bool AMin(int a,int b,int c);
int SearchMin(int S1[],int S2[],int S3[],int s1,int s2,int s3);//S为数组，s为数组长度
int main(){
  int S1[]={-1,0,9};
  int S2[]={-25,-10,10,11};
  int S3[]={2,9,17,20,21};
  printf("%d",SearchMin(S1,S2,S3,3,4,5));
  system("pause");
}
bool AMin(int a,int b,int c){
  if(a<=b && a<=c){
    return true;
  }
  return false;
}
int SearchMin(int S1[],int S2[],int S3[],int s1,int s2,int s3){
  int DMin = abs(S1[0]-S2[0])+abs(S2[0]-S3[0])+abs(S2[0]-S3[0]);//最小距离
  int D;//距离
  for(int i=0,j=0,k=0;i<s1&&j<s2&&k<s3;){
    D = abs(S1[i]-S2[j])+abs(S2[j]-S3[k])+abs(S3[k]-S1[i]);
    if(DMin>D){
      DMin = D;
    }
    if(AMin(S1[i],S2[j],S3[k])){
      i++;
    }else if(AMin(S2[j],S1[i],S3[k])){
      j++;
    }else{
      k++;
    }
  }
  return DMin;
}