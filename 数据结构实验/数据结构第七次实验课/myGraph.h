#ifndef MYGRAPH_H
#define MYGRAPH_H
#include<iostream>
#include<climits>
#define MAXN 20
#define MaxInt INT_MAX
using namespace std;

typedef char VertexType;
typedef int ArcType;

typedef struct{
	VertexType vexs[MAXN];
	ArcType arcs[MAXN][MAXN];
	int vexnum, arcnum;
}MGraph;

// 找到n在G中的对应位置 
int LocateVex(MGraph G, VertexType n)
{
	int num = 0;
	while(G.vexs[num] != n) num++;
	return num;
}

void CreatUDG(MGraph &G)
{
	cin >> G.vexnum >> G.arcnum;
	// 输入顶点信息 
	for(int i = 0;i < G.vexnum;i++)
	{
		cin >> G.vexs[i];
	}
	
	// 初始化邻接矩阵，边的权值均置为极大值MaxInt 
	for(int i = 0;i < G.vexnum;i++)
		for(int j = 0;j < G.vexnum;j++)
			G.arcs[i][j] = MaxInt;
			
	// 构造邻接矩阵 
	for(int i = 0;i < G.arcnum;i++)
	{
		VertexType v1, v2;
		ArcType w;
		cin >> v1 >> v2 >> w;
		int x = LocateVex(G, v1);
		int y = LocateVex(G, v2);
//		cout << x << " " << y << " " << w << endl;
		G.arcs[x][y] = w;
		G.arcs[y][x] = G.arcs[x][y];	// 无向图是对称矩阵 
	}
		
}


// ∞
void PrintUDG(MGraph G)
{
	for(int i = 0;i < G.arcnum;i++)
	{
		for(int j = 0;j < G.arcnum;j++)
		{
			if(G.arcs[i][j] != MaxInt) cout << G.arcs[i][j] << "   ";
			else cout << "∞" << " ";
		}
		cout << endl;	
	}		
}


int FirstAdjVex(MGraph G, int v)
{
	for(int i = 0;i < G.vexnum;i++)
	{
		if(G.arcs[v][i] != MaxInt) return i;
	}
	return -1;
}

int NextAdjVex(MGraph G, int v, int w)
{
	if(G.arcs[v][w] != MaxInt)
	{
		for(int i = w + 1;i < G.vexnum;i++)
		{
			if(G.arcs[v][i] != MaxInt) return i;
		}
		return -1;
	}
	return -1;
}
#endif
