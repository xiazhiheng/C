#include<iostream>
// #include<limits.h>
using namespace std;
#define MaxSize 5
typedef struct{
  int p[MaxSize];//价格
  int v[MaxSize];//体积
}List;
int method1(List list,int i,int c);//蛮力枚举
int method2(List list,int i,int c);//带备忘录的递归
int method3(List list,int n,int c);//递推
int P[6][14] = {0};
int R[5][13] = {0};
int m1=0,m2=0;
int main(){
  List list;
  list.p[0] = 24;
  list.v[0] = 10;

  list.p[1] = 2;
  list.v[1] = 3;

  list.p[2] = 9;
  list.v[2] = 4;

  list.p[3] = 10;
  list.v[3] = 5;

  list.p[4] = 9;
  list.v[4] = 4;
  printf("%d\n",method3(list,5,13));

  for(int i=0;i<5;i++){
    for(int j=0;j<13;j++){
      printf("%d ",R[i][j]);
    }
    printf("\n");
  }
  system("pause");
}
int method1(List list,int i,int c){
  m1++;
  if(c<0){
    return INT32_MIN;
  }
  if(i<0){
    return 0;
  }
  return max(method1(list,i-1,c-list.v[i])+list.p[i],method1(list,i-1,c));
}
int method2(List list,int i,int c){
  m2++;
  if(c<0){
    return INT32_MIN;
  }
  if(i<0){
    return 0;
  }
  if(P[i][c]!=0){
    return P[i][c];
  }
  P[i][c] = max(method2(list,i-1,c-list.v[i])+list.p[i],method2(list,i-1,c));
}
int method3(List list,int n,int c){
  // //初始化
  // for(int i=0;i<c;i++){
  //   P[0][c] = 0;
  // }
  // for(int i=0;i<n;i++){
  //   P[i][0] = 0;
  // }
  int a,b;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=c;j++){
      if(j>=list.v[i-1]){
        a = P[i-1][j-list.v[i-1]]+list.p[i-1];
        b = P[i-1][j]; 
        if(a>b){
          P[i][j] = a;
          R[i-1][j-1] = 1;
        }else{
          P[i][j] = b;
        }
      }else{
        P[i][j] = P[i-1][j];
      }
    }
  }
  return P[n][c];
}
