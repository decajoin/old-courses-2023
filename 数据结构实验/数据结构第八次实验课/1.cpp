#include<iostream>

using namespace std;


typedef struct{
	int key; // 关键字域
	int data;// 其他字域
}Node; 

typedef struct{
	Node *elem;
	int length;
}SSTable; // 定义顺序表

void InitTable(SSTable &S, int n)
{
	S.elem = (Node*)malloc(sizeof(Node) * n);
	S.length = n;
}

void slowfind(SSTable S, int x)
{
	int cns = 0;
	bool flag; // 判断是否找到目标
	for(int i = S.length - 1; i >= 0; i--) 
	{
		cns++;
		if(S.elem[i].key == x) 
		{
			cout << "Find" << " ";
			cout << cns << endl;
			flag = true;
		}
	}
	if(!flag)
	{
		cout << "NotFind" << " ";
		cout << cns << endl;
	}
}

void fastfind(SSTable S, int x)
{
	int l = 0, r = S.length - 1;
	int cns = 0;
	while(l <= r)
	{
		cns++;
		int mid = (l + r) >> 1;
		if(S.elem[mid].key == x) 
		{
			cout << "Find" << " ";
			cout << cns << endl;
			return;	 
		}
		else if(S.elem[mid].key < x) l = mid + 1;
		else r = mid - 1;
	}
	
	cout << "NotFind" << " ";
	cout << cns << endl;	
	return;	

}
int main()
{
	int n, x;
	SSTable S;
	cin >> n;
	InitTable(S, n);

	for(int i = 0; i < n; i++)
	{
		cin >> S.elem[i].key >> S.elem[i].data;
	}
	
	cin >> x;
	slowfind(S, x);
	fastfind(S, x);
	
	return 0;
}
