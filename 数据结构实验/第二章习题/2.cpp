#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct Node{
	int data;
	struct Node *next;
}LNode,*LinkList;


void InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
}

void CreatList(LinkList &L,int n)
{
	LinkList p,r;
	r = L;
	for(int i = 0;i < n;i++)
	{
		int data;
		cin >> data;
		p = (LinkList)malloc(sizeof(LNode));
		p->data = data;
		p->next = NULL;
		r->next = p; 
		r = p;
	}
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

bool ListInsert(LinkList &L,int i,int e)
{
	if(i < 1 ) 
	{
		cout<< "Insertion Location Error" << endl;
		return false;
	}
	
	LinkList r = L,p;
	for(int j = 0;j < i - 1;j++)
	{
		r = r->next;
	}
	
	if(r == NULL)
	{
		cout<< "Insertion Location Error" << endl;
		return false;		
	} 

	p = (LinkList)malloc(sizeof(LNode));
	p->data = e;
	p->next = r->next;
	r->next = p;
	return true;
}


bool ListDelete(LinkList &L,int n,int &e)
{
	if(n < 1)
	{
		cout<< "Deletion Location Error" << endl;
		return false;	
	}
	
	LinkList r = L,p;
	for(int j = 0;j < n - 1;j++)
	{
		r = r->next;
	}
	if(r->next == NULL) // 注意我们删除第n个元素时是找到n前面那个元素 
	{
		cout<< "Deletion Location Error" << endl;
		return false;
	}
	
    p = r->next;
	e = r->next->data;
	r->next = p->next;
    free(p);
}

int ListLength(LinkList L)
{
	LinkList r = L->next;
	int cnt = 0;
	while(r != NULL)
	{
		cnt++;
		r = r->next;
	}
	return cnt;
}

LinkList merge(LinkList &L1,LinkList &L2)
{
	LinkList hc;
	int len1 = ListLength(L1);
	int len2 = ListLength(L2);
	if(len1 == 0 && len2 > 0) hc = L2;
	else if(len2 == 0 && len1 > 0) hc = L1;
	else if(len1 >= len2)
	{
		hc = L2;
		LinkList r;
		r = L2;
		while(r->next != NULL)
		{
			r = r->next;
		}
		r->next = L1->next;
	}
	else if(len1 < len2)
	{
		hc = L1;
		LinkList r;
		r = L1;
		while(r->next != NULL)
		{
			r = r->next;
		}
		r->next = L2->next;		
	}
	return hc;
}

void deletrange(LinkList &L,int mink,int maxk)	// 链表是单增的 
{
	LinkList l,r;
	l = L;
	r = L;
	while(l->next->data < mink)
	{
		l = l->next;
	}
	while(r->next->data < maxk)
	{
		r = r->next;
	}
	LinkList x;
	x = l->next;	
	l->next = r->next->next;
	free(x);
}

void inverse(LinkList L)
{
    LinkList p;
    p = L->next;
    L->next = NULL;
    while(p != NULL)
	{
        LNode *tmp;
        tmp = p->next;
        p->next = L->next;
        L->next = p;
        p = tmp;
    }
}

void initlist(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
}
void creatlist(LinkList &L,int n)
{
	int x;
	cin >> x;
	L->data = x;
	LinkList r;
	r = L;
	for(int i = 0;i < n - 1;i++)
	{
		cin >> x;
		LinkList p;
		p = (LinkList)malloc(sizeof(LNode));
		p->data = x;
		r->next = p;
		p->next = L;
		r = p;	
	}
}
LinkList locationlist(LinkList L,LinkList p)
{
	LinkList q;
	q = p;
	while(q->next != p)
	{
		q = q->next;
	}
	return q;
}
void deletlist(LinkList &L,LinkList s)
{
	LinkList p1, p2;
	p1 = locationlist(L,s);
	p2 = locationlist(L,p1);
	p2->next = s;
	free(p1);
}
void printlist(LinkList L,LinkList s)
{
	LinkList p = s;
	while(p->next != s)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data;
}

int main()
{
	LinkList L1;
	LinkList L2;
	
	int x;
	cin >> x;
	initlist(L1);
	creatlist(L1,x);
	LinkList s;
	s = L1->next;
	cout<< s->data <<endl;
	deletlist(L1,s);
	printlist(L1,s);
	
	
 	return 0;
}
