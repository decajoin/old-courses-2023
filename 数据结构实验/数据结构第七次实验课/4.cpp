#include"myGraph.h"
#include"myQueue1.h"

using namespace std;
bool vis[MAXN];

void BFS(MGraph G, int v)
{
	// 按广度优先非递归遍历图G，使用辅助队列Q 
	LinkQueue Q;
	InitQueue(Q);
	
	for(int v = 0; v < G.vexnum; v++)
	{
		if(!vis[v])
		{
			vis[v] = true;
			cout << G.vexs[v] << " ";
			EnQueue(Q, v);
			
			while(!isEmptyQueue(Q))
			{
				int u;
				DeQueue(Q, u);
				for(int w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
					if(!vis[w])
					{
						vis[w] = true;
						cout << G.vexs[w] << " ";
						EnQueue(Q, w);
					}
			}				
		}
	
	}

	
}

int main()
{
	MGraph G; 
	CreatUDG(G);
	
	BFS(G, 0);
	return 0;
}
