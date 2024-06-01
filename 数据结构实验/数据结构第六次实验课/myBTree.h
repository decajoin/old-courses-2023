#ifndef MYBTREE_H
#define MYBTREE_H
#include<iostream>
#include"myQueue.h"
using namespace std;
//typedef struct BiTNode{
//	char data;
//	struct BiTNode *lchild, *rchild;
//}BiTNode, *BiTree;

// 创建树 
void CreatBiTree(BiTree &T)
{
	char a;
	cin >> a;
	if(a == '*') T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = a;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);
	}
}

// 先序遍历 
void PreOrder(BiTree T)
{
	if(T)
	{
		cout << T->data;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

// 中序遍历 
void InOrder(BiTree T)
{
	if(T)
	{
		InOrder(T->lchild);
		cout << T->data;
		InOrder(T->rchild);
	}
}

// 后序遍历 
void PostOrder(BiTree T)
{
	if(T)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout << T->data;
	}
}

// 求二叉树的叶子结点数 
// 开全局变量的方法 
int cnt = 0;
int LeefCount1(BiTree T)
{
	if(T)
	{
		if(T->lchild == NULL && T->rchild == NULL)
		{
			cnt++;
		}
		LeefCount1(T->lchild);
		LeefCount1(T->rchild);
	}
	return cnt;
}

// 求二叉树的叶子结点数 
// 不开全局变量 
int LeefCount2(BiTree T)
{
	if(T == NULL) return 0;
	if(T->rchild == NULL && T->lchild == NULL) return 1;
	return LeefCount2(T->lchild) + LeefCount2(T->rchild);	
}

// 求树的深度 
int dcount = 0;
int dL = 0, dR = 0;
int DeepCount(BiTree T)
{
	if(T == NULL) dcount = 0;
	else
	{
		dL = DeepCount(T->lchild);	//计算左子树的深度 
		dR = DeepCount(T->rchild);	//计算右子树的深度 
		dcount = 1 + (dL > dR ? dL : dR);	//二叉树的深度为较大者加1(加上刚开始的根结点)
	}
	return dcount;	
}

// 交换树的左子树和右子树 
void InverseTree(BiTree &T)
{
	BiTree temp;
	if(T == NULL) return;
	else
	{
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;
		InverseTree(T->lchild);
		InverseTree(T->rchild);		
	}
}

// 层次遍历 
void LayerOrder(BiTree T)
{
	LinkQueue Q;	// 创建队列 
	BiTree a;		// 创建一个树节点a 
	InitQueue(Q);	// 初始化队列 
	EnQueue(Q, T);	// 将根节点入队 
	while(!isEmptyQueue(Q))	// 循环直到队空 
	{
		DeQueue(Q, a);		// 出队元素(指针)，赋给a 
		cout << a->data;	// 访问a所指结点
		if(a->lchild != NULL) EnQueue(Q, a->lchild);	// 入队a的左孩子 
		if(a->rchild != NULL) EnQueue(Q, a->rchild);	// 入队a的右孩子 
	}
}
#endif 


