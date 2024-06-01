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

void ListInsert(SqList &L,int i,int e) // 在i个位置插入元素e
{
    if(i < 1 || i > L.listsize + 1) return;
    if(L.length >= L.listsize)
    {
    	int *newbase;
        newbase = (int*)realloc(L.elem,sizeof(int)*(L.listsize + LISTINCREMENT));
        if(!newbase) exit(0);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    int* q;
    int* p;
    q = &(L.elem[i - 1]);
    
    for(p = &(L.elem[L.length - 1]);p > q;p--)
    {
        *(p + 1) = *p ;// 插入的元素向后移
    }
    *q = e;
    L.length++;
}

void ListDelet(SqList &L,int i,int &e)
{
    if(i < 1 || i > L.listsize) return ;
    int* p = &(L.elem[i - 1]);
    int* q = &(L.elem[L.length - 1]);
    e = L.elem[i - 1];
    for(p++;p <= q;p++)
    {
        *(p - 1) = *p; // 被删除元素以后的元素向左移
    }
    
    L.length--;
}

void PrintList(SqList L)
{
    for(int i = 0;i < L.length;i++) cout<<L.elem[i]<<" ";
    cout<<endl;
}

int LocateElem(SqList L,int e)
{
	int i = 0;
	int* p;
	p = &(L.elem[0]);
    while(*(p + i)!= e && i <= L.length)
    {
		i++;
	}
	if(i < L.length) return i + 1;
	else return 0;
}
int main(){
	int e,n,x;
    SqList L1;
	InitList(L1);
	
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		ListInsert(L1,i,x);
	}
	
	cin >> x;
	ListDelet(L1,x,e);
	
	cin >> x;
	LocateElem(L1,x);
	
	PrintList(L1);
	
	cout << e << endl;
	
	if(LocateElem(L1,x))	cout << LocateElem(L1,x) << endl;
	else cout<< "Not find" << endl;
	
    return 0;
}
