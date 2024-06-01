#include <iostream>     
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

void ListDelet(SqList &L,int i)
{
    if(i < 1 || i > L.listsize) return ;
    int* p = &(L.elem[i - 1]);
    int* q = &(L.elem[L.length - 1]);
    
    for(p++;p <= q;p++)
    {
        *(p - 1) = *p; // 被删除元素以后的元素向左移
    }
    
    L.length--;
}

void List_set(SqList &L)
{
	for(int i = 0;i < L.length - 1;i++)
	{
		if(L.elem[i] == L.elem[i + 1])
		{
			for(int j = i;j < L.length - 1;j++)
			{
				L.elem[j] = L.elem[j + 1];
			}
			L.length--;
			i--;
		}
	}
		
}
int main(){
	int n,x;
    SqList L1;
	InitList(L1);
	
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		ListInsert_sort(L1,x);
	}
	
	List_set(L1);
	
	PrintList(L1);
	
    return 0;
}
