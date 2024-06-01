#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node
{
	int num;
	struct node *next; 
}Lnode,*pNode;

void InitNode(pNode &N)
{
	N = (pNode)malloc(sizeof(Lnode));
	N->next = NULL;	
}

void InertNode(pNode &N, int x) // 头插法保证顺序
{
	pNode p = N;
	pNode q = (pNode)malloc(sizeof(Lnode));
	q->num = x;
	q->next = p->next;
	p->next = q;
}

void PrintNode(pNode N)
{
	pNode p = N;
	while(p->next != NULL)
	{
		cout << p->next->num;
		p = p->next;
	}
}

int main()
{
	pNode N;
	InitNode(N);
	
	int n, a;
	cout << "请输入一个需转换的正整数:" << endl;
	cin >> n;
	cout << "需转换成几进制的数(2～9)?" << endl;
	cin >> a;
	
	while(n != 1)
	{
		int x;
		x = n - a * (n / a);
		n /= a;
		InertNode(N, x);
	}
	InertNode(N, 1); // 加入最后剩下的1
	
	
	PrintNode(N);
	return 0;
}
