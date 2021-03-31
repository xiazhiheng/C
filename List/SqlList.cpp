#include<iostream>
using namespace std;
#define MaxSize 10

SqlList* InitList(SqlList *sqlList);
bool ListInsert(SqlList *sqlList,int i,int data);
bool ListDelete(SqlList *sqlList,int i);

typedef struct{
  int data[MaxSize];
  int length;
}SqlList;
int main(){

}
SqlList* InitList(SqlList *sqlList){
  sqlList = (SqlList*)malloc(sizeof(SqlList)*MaxSize);
  sqlList->length = 0;
  return sqlList;
}
bool ListInsert(SqlList *sqlList,int i,int data){
  if(i > sqlList->length || i<1){
    return false;
  }
  if(sqlList->length == MaxSize){
    return false;
  }
  for(int j=sqlList->length;j>i-1;j--){
    sqlList->data[j] = sqlList->data[j-1];
  }
  sqlList->data[i-1] = data;
  sqlList->length++;
  return true;
}
bool ListDelete(SqlList *sqlList,int i){
  if(i > sqlList->length-1 || i<1){
    return false;
  }
  if(sqlList->length<1){
    return false;
  }
  for(int j=i-1;j<sqlList->length-1;j++){
    sqlList[j]=sqlList[j+1];
  }
  sqlList->length--;
  return true;
}