/*
#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node {
	int num;
	struct node* next;
} Lnode, * pNode;

pNode CreatLinkList(pNode L, int m)
{
	if(m < 1)	// 数量小于1是不存在链表
	{
		L = NULL;
		return L;
	}

	L = (pNode)malloc(sizeof(Lnode));
	L->num = 1;
	pNode p = L;
	for(int i = 2; i <= m; i++)
	{
		pNode q = (pNode)malloc(sizeof(Lnode));
		q->num = i;
		p->next = q;
		p = q;
	}
	p->next = L;	// 将尾指针与头指针相连形成循环链表

	return p;	// 返回尾指针（方便后面删除节点）
}

int MonkeyKing(pNode &rear, int n)
{
	if(rear == NULL) return 0;

	pNode p = rear;
	while(p->next != p)
	{
		for(int i = 1; i < n; i++)
		{
			p = p->next;
		}
		pNode q	= p->next;
		p->next = q->next;
		free(q);
	}
	int kingnum = p->num;
	return kingnum;
}


int main()
{
	int m, n;
	pNode L;
	cout << "请输入猴子数M及报数上限N：" << endl;
	cin >> m >> n;
	pNode rear = CreatLinkList(L, m);
	cout << "大王是" << MonkeyKing(rear, n) << "号猴子";
	return 0;
}
*/