#include"myGraph.h"

using namespace std;
bool vis[MAXN];
void DFS(MGraph G, int v)
{
	cout << G.vexs[v] << " ";
	vis[v] = true;
	//依次检查V的所有邻接点w，FirstAdjVex(G, v)表示v的第一个邻接点  
	// NextAdjVex(G, v, w)表示v的相对于w的下一个邻接点，w≥0表示存在邻接点 
	for(int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
		if(!vis[w]) DFS(G, w);
}
int main()
{
	MGraph G; 
	CreatUDG(G);
	
	// 保证在非联通图的状态下也能实现全部访问 
	for(int v = 0; v < G.vexnum; v++) 
		if(!vis[v]) DFS(G, v);
	
	return 0;
}
