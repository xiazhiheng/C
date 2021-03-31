#include<iostream>
using namespace std;
int* input(int *n,int *len);
void method(int *num,int len,int *max,int *min);
int main(){
  // int n[10] = {1,3,2,4,7,6,7,5,10,9};
  int *n;
  int len = 0;
  n = input(n,&len);
  int max;
  int min;
  max = n[0];
  min = n[0];
  method(n,len,&max,&min);
  printf("min=%d,max=%d",min,max);
  system("pause");
}
int* input(int *n,int *len){
  printf("输入数组长度\n");
  scanf("%d",len);
  n = (int *)malloc(sizeof(int)*(*len));
  printf("输入数组\n");
  for(int i=0;i<*len;i++){
    scanf("%d",&n[i]);
  }
  return n;
}
void method(int *num,int len,int *max,int *min){
  int i = 0;
  while(i<len){
    if(*max<num[i]){
      *max = num[i]; 
    }else if(*min>num[i]){
      *min = num[i];
    }
    i++;
  }
}