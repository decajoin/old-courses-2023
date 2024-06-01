#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct Node{
	int num;
	int x;
	struct Node *next;
}LNode,*LinkList;

void InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
}

void ListInsert(LinkList &L,int n)
{
	LinkList r = L,p;
	for(int i = 0;i < n;i++)
	{
		int num,x;
		cin >> num >> x;
		p = (LinkList)malloc(sizeof(LNode));
		p->num = num;
		p->x = x;
		r->next = p;
		p->next = NULL;
		r = p;
	}
}

void PrintList(LinkList &L)
{
	LinkList r = L->next;
	
	while(r != NULL)
	{
		cout << r->num << " " << r->x<<" ";
		r = r->next;
	}
	cout << endl;
}


void sum(LinkList &L1,LinkList &L2,LinkList &L3)
{
	LinkList p1 = L1->next,p2 = L2->next;
	LinkList p3 = L3;
	while(p1 && p2)
	{
		if(p1->x > p2->x)
		{
			p3->next = p1;
			p1 = p1->next;
			p3 = p3->next;
			p3->next = NULL;
		}
		else if(p1->x < p2->x)
		{
			p3->next = p2;
			p2 = p2->next;
			p3 = p3->next;	
			p3->next = NULL;		
		}
		else
		{
			p3->next = p1;
			p3->next->num = p1->num + p2->num;
			p1 = p1->next;
			p2 = p2->next;
			p3 = p3->next;
			p3->next = NULL;
		}
	}
	p3->next = p1 ? p1 : p2;
}

int main()
{
	int n1,n2;

	LinkList L1,L2,L3;
    
	InitList(L1);
	InitList(L2);
	InitList(L3);
    
    cin >> n1;
	ListInsert(L1,n1);
	cin >> n2;
	ListInsert(L2,n2);
    
	sum(L1,L2,L3);
    
	PrintList(L3);
	return 0;
}
