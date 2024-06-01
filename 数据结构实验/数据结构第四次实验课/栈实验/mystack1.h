#ifndef MYSTACK1_H
#define MYSTACK1_H
#include<iostream>
#include<stdlib.h>
using namespace std;

#define INIT_SIZE 100	// 存储空间初始分配量
#define INCREMENT 10	//存储空间分配增量

typedef struct{
	int *base;
	int *top;
	int StackSize;
}SqStack;
 
void InitStack(SqStack &S)
{
	S.base = (int*)malloc(INIT_SIZE*sizeof(int));
	if(!S.base) exit(-1);
	S.top = S.base;
	S.StackSize = INIT_SIZE;
	return;
}

bool StackEmpty(SqStack S)
{
	if(!S.base) exit(-1);
	if(S.top == S.base) return true;
	else return false;
}

void push(SqStack &S,int x)
{
	if(S.top - S.base == S.StackSize)	//栈满 
	{	
		int *newbase;	//准备新基址 
		newbase = (int*)realloc(S.base,(S.StackSize + INCREMENT)*sizeof(int));
		if(!newbase) exit(-1);
		S.base = newbase;
		S.top = S.StackSize + S.base;	// 找到现在top指针的位置  
		S.StackSize += INCREMENT;
	}
	*S.top++ = x;	// 由于赋值后top++，top始终是空的 
	return;
}

void pop(SqStack &S,int &e)
{
	if(S.top == S.base) exit(-1);
	e = *--S.top;
}

void top(SqStack S,int &e)
{
	if(S.top == S.base) return;
	e = *(S.top - 1);
}

void travel(SqStack S)	// 将栈的数据元素从栈底到栈顶依次显示
{
	while(S.top != S.base)
	{
		cout << *S.base++ << " ";
	}
	cout << endl;
}

#endif
