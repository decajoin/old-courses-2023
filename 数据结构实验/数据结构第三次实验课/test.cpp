#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct LNode_{
	int code;
	int key;
	struct LNode_ *next;
}LNode,*LinkList;

int n,m;

void InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = L;	// 头尾相连 
}

void CreatList(LinkList &L)	// 尾插法给链表赋值 
{
	L->code = 1;
	int key;
	cin >> key;
	L->key = key;
	LinkList p = L;
	for(int i = 2;i <= n;i++)
	{
		LinkList q;
		q = (LinkList)malloc(sizeof(LNode));
		q->code = i;
		cin >> key;
		q->key = key;
		p->next = q;
		p = q;
	}
	p->next = L;	// 最后将尾结点的next指向头节点，来实现头尾相连，形成循环链表 
}

void Joseph(LinkList &L,int m)
{
	LinkList p = L;
	int x = 1;
	while(p->next != p)	// p->next == p表示还剩一个结点 
	{
		 
	}
	cout << p->code;
}
int main()
{
	LinkList L;
	cin >> m >> n;
	InitList(L);
	CreatList(L);
	Joseph(L,m);
	return 0;
}
