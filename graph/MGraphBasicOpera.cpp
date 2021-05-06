#include <iostream>
using namespace std;
#define MaxSize 10
typedef char VertexType;//顶点的数据类型
typedef int EdgeType;//带权图中边上权值的数据类型
typedef struct{
    VertexType vex[MaxSize];//顶点表
    EdgeType Edge[MaxSize][MaxSize];//领接矩阵，边表
    int vexnum,arcnum;//图的当前顶点数和弧数
}MGraph;
int VexPos(MGraph g,VertexType x);//返回顶点x的序号，无则返回-1
bool Adjacent(MGraph g,VertexType x,VertexType y);//判断图是否存在边xy
void Neighbors(MGraph g,VertexType x);//列出图中与顶点x的邻接的边
bool InsertVertex(MGraph g,VertexType x);//在图中插入顶点x
bool DeleteVertex(MGraph g,VertexType x);//在图中删除顶点x
bool AddEdge(MGraph g,VertexType x,VertexType y);//添加边xy
bool RemoveEdge(MGraph g,VertexType x,VertexType y);//移除边xy
int FristNeighbor(MGraph g,VertexType x);//返回图中x的第一个邻接点，有则返回顶点号，无则返回-1
int NextNeighbor(MGraph g,VertexType x,VertexType y);//返回图中x除y以外的下一个邻接节点的顶点号，无则返回-1

EdgeType Get_edge_value(MGraph g,VertexType x,VertexType y);//返回图中边xy的权值 
bool Set_edge_value(MGraph g,VertexType x,VertexType y);//设置边xy的权值
int main()
{
    
    system("pause");
}
int VexPos(MGraph g,VertexType x){
    for(int i=0;i<g.vexnum;i++){
        if(g.vex[i]==x){
            return i;
        }
    }
    return -1;
}
bool Adjacent(MGraph g,VertexType x,VertexType y){
    int i=0,j=0;
    while(i<g.vexnum){
        if(g.vex[i]==x)
            break;
        i++;
    }
    while(j<g.vexnum){
        if(g.vex[j]==y)
            break;
        j++;
    }
    if(i==g.vexnum || j==g.vexnum){
        return false;
    }
    if(g.Edge[i][j]==1){
        return true;
    }
    return false;
}
void Neighbors(MGraph g,VertexType x){
    int i=0;
    while(i<g.vexnum){
        if(g.vex[i]==x){
            break;
        }
        i++;
    }
    if(i!=g.vexnum){
        for(int j=0;j<g.vexnum;j++){
            if(g.Edge[i][j]==1){
                printf("%c%c ",g.vex[i],g.vex[j]);
            }
        }
        printf("\n");
    }
}
bool InsertVertex(MGraph g,VertexType x){
    if(g.vexnum==MaxSize){
        return false;
    }
    g.vex[g.vexnum] = x;
    for(int i=0;i<=g.vexnum;i++){
        g.Edge[g.vexnum][i] = 0;
        g.Edge[i][g.vexnum] = 0;
    }
    g.vexnum++;
    return tr int i=0,j=0;
    while(i<g.vexnum){
        if(g.vex[i]==x)
            break;
        i++;
    }
    while(j<g.vexnum){
        if(g.vex[j]==y)
            break;
        j++;
    }
    if(i==g.vexnum || j==g.vexnum){
        return false;
    }
}
bool DeleteVertex(MGraph g,VertexType x){
    if(g.vexnum<2){
        return false;
    }
    int i = VexPos(g,x);
    if(i==-1){
        return false; 
    }
    g.vex[i] = g.vex[g.vexnum-1];
    g.vexnum--;
    for(int j=0;j<g.vexnum;j++){
        g.Edge[j][i] == g.Edge[j][g.vexnum];
        g.Edge[i][j] == g.Edge[g.vexnum][j];
    }
    return true;
}
bool AddEdge(MGraph g,VertexType x,VertexType y){
    int i = VexPos(g,x);
    int j = VexPos(g,y);
    if(i==-1 || j==-1){
        return false;
    }
    g.Edge[i][j] = 1;
    return true;
}
bool RemoveEdge(MGraph g,VertexType x,VertexType y){
    int i = VexPos(g,x);
    int j = VexPos(g,y);
    if(i==-1 || j==-1){
        return false;
    }
    g.Edge[i][j] = 0;
    return true;
}
int FristNeighbor(MGraph g,VertexType x){
    int i = VexPos(g,x);
    if(i==-1){
        return -1;
    }
    for(int j=0;j<g.vexnum;j++){
        if(g.Edge[i][j]==1){
            return j;
        }
    }
    return -1;
}
int NextNeighbor(MGraph g,VertexType x,VertexType x){
    int i = VexPos(g,x);
    if(i==-1){
        return -1;
    }
    for(int j=0;j<g.vexnum;j++){
        if(g.vex[j]!=y && g.Edge[i][j]==1){
            return j;
        }
    }
    return -1;
}
EdgeType Get_edge_value(MGraph g,VertexType x,VertexType y){

}
bool Set_edge_value(MGraph g,VertexType x,VertexType y){

}

