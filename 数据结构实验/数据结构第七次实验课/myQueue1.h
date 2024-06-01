#ifndef MYQUEUE1_H
#define MYQUEUE1_H
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

void DestroyQueue(LinkQueue &Q)
{
    while(Q.front)
    {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
}
 
 void EnQueue(LinkQueue &Q, int e)
 {
     QueuePtr p;
     p = (QueuePtr)malloc(sizeof(QNode));
     p->data = e;
     p->next = NULL;
     Q.rear->next = p;
     Q.rear = p;
 }
 
 void DeQueue(LinkQueue &Q, int &e)
 {
     QueuePtr p;
     if(Q.front == Q.rear) return;
     p = Q.front->next;
     e = p->data;
     Q.front->next = p->next;
     if(Q.rear == p) Q.rear = Q.front;
     free(p);
 }
 
 void PrintQueue(LinkQueue Q)
 {
     QueuePtr p;
     p = Q.front->next;
     while(p != NULL)
     {
         cout << p->data << " ";
         p = p->next;
     }
 }
 
 bool isEmptyQueue(LinkQueue Q)
 {
    if(Q.front == Q.rear) return true;
    else return false;
 }

 void TopQueue(LinkQueue Q, int &e)
 {
    e = Q.front->next->data;
 }

int QueueLength(LinkQueue Q)
{
	int cnt = 0;
	QueuePtr p;
	p = Q.front->next;
	while(p != NULL)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}
#endif
