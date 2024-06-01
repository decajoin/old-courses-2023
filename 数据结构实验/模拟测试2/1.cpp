#include<iostream>
#include<cstdlib>
using namespace std;

#define initsize  20    //存储空间的初始分配量          
typedef struct {
	int* elem;        //存储空间基址                                     
	int length;             //当前长度                                     
	int listsize;           //当前分配的存储容量
}SqList;


void CreateSqList(SqList& Q, int n)
{
	Q.elem = (int*)malloc(n * sizeof(int));
	Q.listsize = n;
	Q.length = 0;

	cout << "请依次输入顺序表的元素(递增有序)：" << endl;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		Q.elem[i] = a;
	}
	Q.length = n;

}


void DeleteSqList(SqList& Q)
{
	for (int i = 0; i < Q.length - 1; i++)
	{
		if (Q.elem[i] == Q.elem[i + 1])
		{
			for (int j = i; j < Q.length - 1; j++)
			{
				Q.elem[j] = Q.elem[j + 1];
			}
			Q.length--;
			i--;
		}
	}
	cout << Q.length << endl;
}
void PrintSqList(SqList Q)
{
	cout << "删除多余值后顺序表的元素依次为：" << endl;
	for (int i = 0; i < Q.length; i++)
	{
		cout << Q.elem[i] << " ";
	}
}


int main()
{
	SqList Q;
	int n;
	cout << "请输入要建立的顺序表的长度：" << endl;
	cin >> n;
	CreateSqList(Q, n);
	DeleteSqList(Q);
	PrintSqList(Q);
	return 0;
}