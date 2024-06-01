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

int LengthStack(LinkStack S)
{
	int cnt = 0;
	while(S != NULL) cnt++;
	return cnt;
}

void InitStackS(LinkStackS &S)
{
	S = NULL;
}

void pushS(LinkStackS &S,char x)
{
	LinkStackS p;
	p = (LinkStackS)malloc(sizeof(StackNodeS));
	p->data = x;
	p->next = S;
	S = p;
}

void popS(LinkStackS &S,char &e)
{
	LinkStackS p = S;
	e = p->data;
	S = S->next;
	free(p);
}

void topS(LinkStackS S,char &e)
{
	if(S == NULL) return;
	e = S->data;
}

bool StackEmptyS(LinkStackS S)
{
	if(S == NULL) return true;
	else return false;
}

void calculate(LinkStack &numStack,char e)
{
	int num1,num2,res;
	pop(numStack,num2);
	pop(numStack,num1);
	switch(e)
	{
		case '+' : 
		{
			res = num1 + num2;
			push(numStack,res);
		}
		break;
		case '-' :
		{
			res = num1 - num2;
			push(numStack,res);
		}
		break;
		case '*' :
		{
			res = num1 * num2;
			push(numStack,res);
		}
		break;
		case '/' :
		{
			res = num1 / num2;
			push(numStack,res);
		}
		break;
	}
}
#endif
