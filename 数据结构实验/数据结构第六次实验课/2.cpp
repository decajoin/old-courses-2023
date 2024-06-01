#include<iostream>
#include"myBTree.h"
using namespace std;
int main()
{
	BiTree T;

	CreatBiTree(T);
	
	LayerOrder(T);
	return 0;
}
