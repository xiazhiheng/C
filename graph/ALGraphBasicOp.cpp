#include <iostream>
using namespace std;
#define MaxSize 10
typedef char VertexType;//顶点的数据类型
typedef int EdgeType;//带权图中边上权值的数据类型
typedef int InfoType;
typedef struct ArcNode{
  int adjvex;//该弧所指向的顶点的位置
  struct ArcNode *next;//指向下一条弧的指针
  InfoType info;//网的边权值
}ArcNode;
typedef struct VNode{
  VertexType data;//顶点信息
  ArcNode *first;//指向第一条依附该顶点的弧的指针
}VNode,AdjList[MaxSize];
typedef struct{
    AdjList vertices;//邻接表
    int vexnum,arcnum;//图的当前顶点数和弧数
}ALGraph;
bool Adjacent(ALGraph g,VertexType x,VertexType y);//判断图是否存在边xy
void Neighbors(ALGraph g,VertexType x);//列出图中与顶点x的邻接的边
bool InsertVertex(ALGraph g,VertexType x);//在图中插入顶点x
bool DeleteVertex(ALGraph g,VertexType x);//在图中删除顶点x
bool AddEdge(ALGraph g,VertexType x,VertexType y);//添加边xy
bool RemoveEdge(ALGraph g,VertexType x,VertexType y);//移除边xy
int FristNeighbor(ALGraph g,VertexType x);//返回图中x的第一个邻接点，有则返回顶点号，无则返回-1
int NextNeighbor(ALGraph g,VertexType x,VertexType y);//返回图中x除y以外的下一个邻接节点的顶点号，无则返回-1

EdgeType Get_edge_value(ALGraph g,VertexType x,VertexType y);//返回图中边xy的权值 
bool Set_edge_value(ALGraph g,VertexType x,VertexType y);//设置边xy的权值
int main()
{
    system("pause");
}
bool Adjacent(ALGraph g,VertexType x,VertexType y);
void Neighbors(ALGraph g,VertexType x);
bool InsertVertex(ALGraph g,VertexType x);
bool DeleteVertex(ALGraph g,VertexType x);
bool AddEdge(ALGraph g,VertexType x,VertexType y);
bool RemoveEdge(ALGraph g,VertexType x,VertexType y);
int FristNeighbor(ALGraph g,VertexType x);
int NextNeighbor(ALGraph g,VertexType x,VertexType y);