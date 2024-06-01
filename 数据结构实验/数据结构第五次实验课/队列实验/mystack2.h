#ifndef MYSTACK2_H
#define MYSTACK2_H
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct StackNode{
	int data;
	struct StackNode *next;
}SNode,*LinkStack;

typedef struct StackNodeS{
	char data;
	struct StackNodeS *next;
}SNodeS,*LinkStackS;

void InitStack(LinkStack &S)
{
	S = NULL;	// S是栈顶 
}

bool StackEmpty(LinkStack S)
{
	if(S == NULL) return true;
	else return false;
}

void push(LinkStack &S,int x)	// 不用考虑栈满问题 
{
	LinkStack p;
	p = (LinkStack)malloc(sizeof(SNode));
	p->data = x;
	p->next = S;  
	S = p;	// 移动S使之成为栈顶 
}

void pop(LinkStack &S,int &e)
{
	if(S == NULL) return;
	LinkStack p;
	p = S;
	e = p->data;
	S = S->next;
	free(p);
}

void top(LinkStack S,int &e)
{
	if(S == NULL) return;
	e = S->data;
}

void travel(LinkStack S)	// 将栈的数据元素从栈顶到栈底依次显示 
{
	while(S != NULL)
	{
		cout << S->data << " ";
		S = S->next;
	}
}

int StackLength(LinkStack S)
{
	int cnt = 0;
	while(S != NULL)
	{
		cnt++;
		S = S->next;
	}
	return cnt;
}

int StackFind(LinkStack S, int num)
{
	int cnt = 0;
	int flag = 0;
	if(S->data / 10000 == num) return 0;
	while(S->data / 10000 != num && S != NULL)
	{
		cnt++;
		flag = 1;
		S = S->next;
	}
	if(flag) return cnt;
	else return -1;
}

#endif
