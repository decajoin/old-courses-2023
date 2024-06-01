#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

typedef struct 
{
	bool  *elem;        	//存储空间基址
	int length;             //当前长度
	int listsize;           //当前分配的存储容量 
}SqList;

void InitSqList(SqList &L, int n)
{
	L.elem = (bool*)malloc(n * sizeof(bool));
	memset(L.elem, 0, n * sizeof(bool));
	L.length = 0;
	L.listsize = n;
}



int main()
{
	SqList L;
	int n, k;
	
	cout << "请输入山洞的个数：" << endl;
	cin >> n;
	cout << "请输入狐狸进出洞的次数：" << endl;
	cin >> k;
	
	InitSqList(L, n + 1);
	
	long long x = 1;
	L.elem[1] = true;	// 第一个洞必进入
	for(int i = 2; i <= k; i++)
	{
		x = x + i;
		int cnt = x % n;
		if(cnt != 0) L.elem[x % n] = true;
		else L.elem[n] = true;
		
	}
	
	cout << "兔子可能藏在下列洞中：" << endl;
	for(int i = 1; i <= n; i++)
	{
		if(L.elem[i] == false) cout << i << " ";
	}
	
	return 0;
}
