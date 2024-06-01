#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct BiTreeNode{
	char data;
	struct BiTreeNode *lchild;
	struct BiTreeNode *rchild;
}BiTreeNode, *BiTree;

typedef struct StackNode{
	BiTree data;
	struct StackNode *next;
}StackNode, *Stack;

void CreatBiTree(BiTree &T)
{
	char x;
	cin >> x;
	// 注意这里是T = NULL!!!
	if(x == '*') T = NULL;	
	else
	{
		T = (BiTree)malloc(sizeof(BiTreeNode));
		T->data = x;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);
	}
}

void InitStack(Stack &S)
{
	S = NULL;
}

void PushStack(Stack &S, BiTree t)
{
	Stack p;
	p = (Stack)malloc(sizeof(StackNode));
	p->data = t;
	p->next = S;
	S = p;
}

void PopStack(Stack &S, BiTree &t)
{
	Stack p;
	p = S;
	t = p->data;
	S = S->next;
	free(p);
}

BiTree TopStack(Stack S)
{
	if(S == NULL) return NULL;
	else return S->data;
}

bool isEmptyStack(Stack S)
{
	if(S == NULL) return true;
	else return false;
}

void PreOrder(BiTree T)
{
	if(T == NULL) return;	
	
	Stack S;
	InitStack(S);
	PushStack(S, T);
	while(!isEmptyStack(S))
	{
		BiTree a = TopStack(S);
		BiTree e;
		
		if(a != NULL)
		{
			PopStack(S, a);
			if(a->rchild) PushStack(S, a->rchild);
			if(a->lchild) PushStack(S, a->lchild);
			PushStack(S, a);
			PushStack(S, NULL);
		}
		else
		{
			PopStack(S, e);
			PopStack(S, a);
			cout << a->data;
		}
	}
}

void InOrder(BiTree T)
{
	if(T == NULL) return;
	
	Stack S;
	InitStack(S);
	PushStack(S, T);
	while(!isEmptyStack(S))
	{
		BiTree a = TopStack(S);
		BiTree e;
		if(a != NULL)
		{
			PopStack(S, a);
			if(a->rchild != NULL) PushStack(S, a->rchild);
			PushStack(S, a);
			PushStack(S, NULL);
			if(a->lchild != NULL) PushStack(S, a->lchild);
			
		}
		else
		{
			PopStack(S, e);
			PopStack(S, a);
			cout << a->data;
		}
	}
}

void PostOrder(BiTree T)
{
	if(T == NULL) return;
	
	Stack S;
	InitStack(S);
	PushStack(S, T);
	while(!isEmptyStack(S))
	{
		BiTree a = TopStack(S);
		BiTree e;
		if(a != NULL)
		{
			PopStack(S, a);
			PushStack(S, a);
			PushStack(S, NULL);
			if(a->rchild != NULL) PushStack(S, a->rchild);
			if(a->lchild != NULL) PushStack(S, a->lchild);
		}
		else
		{
			PopStack(S, e);
			PopStack(S, a);
			cout << a->data;
		}
	}
}




int main()
{
	BiTree T;
	CreatBiTree(T);
	PreOrder(T);
	cout << endl;
	InOrder(T);
	cout << endl;
	PostOrder(T);
	return 0;
}
