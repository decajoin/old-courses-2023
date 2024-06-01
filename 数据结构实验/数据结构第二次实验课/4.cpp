#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define INT_LIST_SIZE 6
#define LISTINCREMENT 3

typedef struct{
    int* elem;
    int length;
    int listsize;
}SqList;

void InitList(SqList &L)
{
    L.elem = (int*)malloc(sizeof(int)*INT_LIST_SIZE);
    memset(L.elem,0,sizeof(int)*INT_LIST_SIZE);
    if(!L.elem) exit(0);
    L.length = 0;
    L.listsize = INT_LIST_SIZE;
}

void PrintList(SqList L)
{
    for(int i = 0;i < L.length;i++) cout<<L.elem[i]<<" ";
    cout<<endl;
}

void ListInsert_sort(SqList &L,int e)
{
	if(L.length >= L.listsize)
	{
	   	int *newbase;
	    newbase = (int*)realloc(L.elem,sizeof(int)*(L.listsize + LISTINCREMENT));
	    if(!newbase) exit(0);
	    L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	
	int* p;
	int i = 0;
	p = &(L.elem[0]);
	while(*(p + i) <= e && i < L.length) i++;
	i++; // 上面循环得到的i是数组的下标，而之前我们后移操作的i是位置故加一 
	
	int* q;
	q = &(L.elem[i - 1]);
	    
	for(p = &(L.elem[L.length - 1]);p >= q;p--)
	{
	    *(p + 1) = *p ;// 插入的元素向后移 
	}
	*q = e;
	L.length++;
}

SqList ListScanf(SqList L1,SqList L2)
{
	SqList L3,L4;
	InitList(L3);
	InitList(L4);
	// 类似归并排序的方法，首先将两个有序表组合 
	int i = 0,j = 0;
	while(i < L1.length && j < L2.length)
	{
		if(L1.elem[i] < L2.elem[j])
		{
			int x = L1.elem[i];
			ListInsert_sort(L3,x);
			i++;
		}
		else
		{
			int x = L2.elem[j];
			ListInsert_sort(L3,x);
			j++;			
		}
	}
	while(i < L1.length)
	{
		int x = L1.elem[i];
		ListInsert_sort(L3,x);
		i++;		
	}
	while(j < L2.length)
	{
		int x = L2.elem[j];
		ListInsert_sort(L3,x);
		j++;		
	}
	
	// 最后遍历上面组合形成的有序表重复的加入L4
for(int i = 0;i < L3.length - 1;i++)
	{
		if(L3.elem[i] == L3.elem[i + 1])
		{
			int x = L3.elem[i];
			ListInsert_sort(L4,x);
		}
	}	
	return L4;
}
int main()
{
	int n,x;
    SqList L1,L2;
	InitList(L1);
	InitList(L2);

	
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		ListInsert_sort(L1,x);
	}
	
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		ListInsert_sort(L2,x);
	}	
//	PrintList(L1);
//	PrintList(L2);
	PrintList(ListScanf(L1,L2));
	return 0;
}
