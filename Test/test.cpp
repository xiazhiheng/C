#include<iostream>
#include<string.h>
using namespace std;
char * convert(char * s, int numRows);

//目标字符串需要足够的空间
//拼接字符串需要以\0结尾
int main(){
    char *str = "abcdefghuij";
    printf("%s",convert(str,3));
    system("pause");
}
char * convert(char * s, int numRows){
    if(numRows<=1){
        return s;
    }
    int len = strlen(s);

    char *ch = (char*)malloc(sizeof(char)*2);
    ch[1] = '\0';

    char *chs[numRows];
    for(int i=0;i<numRows;i++){
        chs[i] = (char*)malloc(sizeof(char)*(len+1));
        chs[i][0] = '\0';
    }

    int flag = 0;
    for(int i=0,row=0;s[i] !='\0';i++){
        ch[0] = s[i];
        chs[row] = strcat(chs[row],ch);
        if(row==0){
            row++;
            flag=0;
        }
        else if(row==numRows-1){
            row--;
            flag=1;
        }
        else if(flag == 0){
            row++;
        }
        else{
            row--;
        }
    }
    char *str = (char*)malloc(sizeof(char)*len+1);
    str[0] = '\0';
    for(int i=0;i<numRows;i++){
        str = strcat(str,chs[i]);
    }
    return str;
}