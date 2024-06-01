#include<iostream>
#include"myBTree.h"
using namespace std;
int main()
{
	BiTree T;
	CreatBiTree(T);
	
	PreOrder(T);
	cout << " ";
	InOrder(T);
	cout << " ";
	PostOrder(T);
	cout << endl;
	
	cout << LeefCount2(T);
	cout << " ";
	cout << DeepCount(T);
	cout << endl;
	
	InverseTree(T);
	
	PreOrder(T);
	cout << " ";
	InOrder(T);
	cout << " ";
	PostOrder(T);	
	
	return 0;
}
