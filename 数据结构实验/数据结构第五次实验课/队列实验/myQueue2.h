#ifndef MYQUEUE2_H
#define MYQUEUE2_H
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct QNode{
    int data;
    struct QNode *next;	
}QNode,*QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

void InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL;
}

void EnQueue(LinkQueue &Q, int e)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	Q.rear->next = Q.front;
}

void DeQueue(LinkQueue &Q, int &e)
{
	if(Q.front == Q.rear) return;
	QueuePtr p;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p) Q.rear = Q.front;
	free(p);
}

void TopQueue(LinkQueue Q, int &e)
{
	e = Q.front->next->data;
}

bool isEmptyQueue(LinkQueue Q)
{
	if(Q.front == Q.rear) return true;
	else return false;
}

void PrintQueue(LinkQueue Q)
{
	QueuePtr p;
	p = Q.front->next;
	while(p != Q.front)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

#endif
