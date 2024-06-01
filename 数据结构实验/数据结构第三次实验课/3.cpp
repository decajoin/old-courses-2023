#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Node{
	int data;
	struct Node* next;
}LNode,*LinkList;

void InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;	
}

void ListInsert(LinkList &L)
{
	int x = 0;
	LinkList p,r;
	p = L; // 尾插法 
	while(cin >> x && x != -1)
	{
		r = (LinkList)malloc(sizeof(Node));
		r->data = x;
		r->next = NULL;
		p->next = r;
		p = r; // p始终是链表的尾 
	}
	return;
}

void PrintList(LinkList &L)
{
	LinkList r = L->next;
	
	while(r != NULL)
	{
		cout << r->data << " ";
		r = r->next;
	}
	cout << endl;
}

void ListSort(LinkList &L1,LinkList &L2,LinkList &L3)
{
	LinkList p1 = L1->next,p2 = L2->next;
	LinkList p3 = L3;
	LinkList r;
	while(p1 && p2)
	{
		if(p2->data > p1->data)
		{
			r = (LinkList)malloc(sizeof(LNode));
			r->data = p1->data;
			p3->next = r;
			p1 = p1->next;
			p3 = p3->next;
		}
		else if(p2->data < p1->data)
		{
 		 	r = (LinkList)malloc(sizeof(LNode));
			r->data = p2->data;
			p3->next = r;
			p2 = p2->next;
			p3 = p3->next;
		}
		else
		{
			r = (LinkList)malloc(sizeof(LNode));
			r->data = p1->data;			
			p3->next = r;
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
	LinkList L1;
	LinkList L2;
	LinkList L3;
	
	InitList(L1);
	ListInsert(L1);
	
	InitList(L2);
	ListInsert(L2);
	
	InitList(L3);
	
	ListSort(L1,L2,L3);
	
	
	PrintList(L3);
	return 0;
}
