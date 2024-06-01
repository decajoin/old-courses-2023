#include<iostream>
#include<cstdlib>
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

void CreatList(LinkList &L,int n)	// 尾插法r为表尾  
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
int main()
{
	LinkList L;
	int n1,n2,n3,x;
	int e;
	
	InitList(L);
	
	cin >> n1;
	CreatList(L,n1);

	cin >> n2 >> x;
	cin >> n3;
	
	ListInsert(L,n2,x);
	
	if(ListDelete(L,n3,e)) cout<< e << endl;// 只有删除操作成功时才输出e 
	
	cout<< ListLength(L) << endl;
	
	PrintList(L);

 	return 0;
}
