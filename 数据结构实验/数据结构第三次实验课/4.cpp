#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Node{
	int code;
	int key;
	struct Node* next;
}LNode,*LinkList;

void InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
}

void ListInsert(LinkList &L,int n)
{
	LinkList r = L,p;
	for(int i = 1;i <= n;i++)
	{
		int m;
		cin >> m;
		p = (LinkList)malloc(sizeof(LNode));
		p->key = m;
		p->code = i;
		p->next = NULL;
		r->next	= p;
		r = p;
	}
}

int pop(LinkList &L)
{
	if(L->next == NULL) exit(0);
	LinkList r = L->next;
	L->next = L->next->next;
	return r->code;
}

void push(LinkList &L)
{
	if(L->next == NULL) return;
	LinkList r = L->next,p = L;
	if(L->next != NULL) L->next = L->next->next;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = r;
	r->next = NULL;
}

void PrintList(LinkList &L)
{
	LinkList r = L->next;
	
	while(r != NULL)
	{
		cout << r->key << " ";
		r = r->next;
	}
	cout << endl;
}

void Joseph(LinkList &L,int m)
{
	while(L->next != NULL)
	{
		for(int i = 0;i < m - 1;i++)
		{
			push(L);
		}
		m = L->next->key;
		cout<< pop(L) << " ";	
	}
}


int main()
{   
	int m,n;
	cin >> m >> n;
	
	LinkList L;
	InitList(L);
	ListInsert(L,n);
	Joseph(L,m);
	PrintList(L);
	
	return 0;
}
