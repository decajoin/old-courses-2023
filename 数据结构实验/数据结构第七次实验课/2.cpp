#include<iostream>
#include<cstdlib>
#define MAXN 20

using namespace std;

typedef char VertexType;
typedef int InfoType;

//边结点的类型定义 
typedef struct ArcNode{
	int adjvex;					// 边的另一顶点的在数组中的位置 
	struct ArcNode *nextarc;	// 指向下一条边的指针
	InfoType info;
}ArcNode; 

//顶点结点 
typedef struct VNode{
	VertexType data;	// 顶点信息
	ArcNode *firstarc;	//指向关联该顶点的边链表 
}VNode, AdjList[MAXN];

typedef struct{
	AdjList vertices;
	int vexnum, arcnum;	// 图的当前顶点数和边数 
}ALGragh;

// 找到n在G中的对应位置 
int LocateVex(ALGragh G, VertexType n)
{
	int num = 0;
	while(G.vertices[num].data != n) num++;
	return num;
}

void CreatUDG(ALGragh &G)
{
	cin >> G.vexnum >> G.arcnum;
	
	//输入各顶点，构造表头结点 
	for(int i = 0; i < G.vexnum;i++)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	
	//输入各边，构造邻接表 
	for(int i = 0;i < G.arcnum;i++)
	{
		VertexType v1, v2;
		InfoType w;
		cin >> v1 >> v2 >> w;
		//确定v1、v2在G中的位置 
		int x = LocateVex(G,v1);
		int y = LocateVex(G,v2);
		
		ArcNode *p1, *p2;
		p1 = (ArcNode*)malloc(sizeof(ArcNode));
		p1->adjvex = y;
		p1->nextarc = G.vertices[x].firstarc;
		p1->info = w;
		G.vertices[x].firstarc = p1;	//将新结点插入到顶点vi的边链表头部 
		
		p2 = (ArcNode*)malloc(sizeof(ArcNode));
		p2->adjvex = x;
		p2->nextarc = G.vertices[y].firstarc;
		p2->info = w;
		G.vertices[y].firstarc = p2;	//将新结点插入到顶点vj的边链表头部 	 	
	}
}

void PrintUDG(ALGragh G)
{
	for(int i = 0;i < G.vexnum;i++)
	{
		cout << G.vertices[i].data << '\t';	// 输出表头结点信息 
		// 输出表头结点连着的信息 
		while(G.vertices[i].firstarc != NULL) 
		{
			cout << G.vertices[i].firstarc->adjvex << " ";	// 输出边结点的序号 
			cout << G.vertices[i].firstarc->info << '\t';	// 输出边的权值 
			G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;	// 指针后移 
		}
		cout << endl;
	}
}
int main()
{
	ALGragh G;
	CreatUDG(G);
	PrintUDG(G);
	return 0;
}
