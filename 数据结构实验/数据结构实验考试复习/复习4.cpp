#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct LinkListNode{
	int num;
	struct LinkListNode *next;
}LinkListNode, *LinkList;

LinkList CreatLinkList(LinkList &L, int m)
{
	if(m < 1)
	{
		L = NULL;
		return L;
	}
	
	L = (LinkList)malloc(sizeof(LinkListNode));
	L->num = 1;
	LinkList p = L;
	for(int i = 2; i <= m; i++)
	{
		LinkList q = (LinkList)malloc(sizeof(LinkListNode));
		q->num = i;
		p->next = q;
		p = q;
	}
	p->next =  L;
	
	return p; // 返回尾指针（方便后面删除）
}

int MokeyKing(LinkList &rear, int n)
{
	if(rear == NULL) return 0;
	
	LinkList p = rear;
	while(p->next != p)	// 判断循环链表只剩下一个的条件
	{
		for(int i = 1; i < n; i++) // 注意移动次数，由于是删除需要移动到目标的前一个位置
		{
			p = p->next;
		}
		// 将报数的猴子删除
		LinkList q = p->next;
		p->next = q->next;
		free(q);
	}
	int kingnum = p->num;
	return kingnum;
}


int main()
{
	LinkList L;
	int m, n;
	cout << "请输入猴子数M及报数上限N：" << endl;
	cin >> m >> n;
	LinkList rear = CreatLinkList(L, m);
	cout << "大王是" << MokeyKing(rear, n) << "号猴子";
	
	return 0;
}
