#include<iostream>
#include<cstdlib>

using namespace std;

typedef char ElemType;
typedef struct bitnode					//定义二叉树节点结构
{     
	ElemType data;                 		//数据域
	struct bitnode *lchild,*rchild;  	//左右孩子指针域 
}BiTNode,*BiTree;


void CreatBitree(BiTree &T) // 创建树
{
	char a;
	cin >> a;
	if(a == '*') T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = a;
		CreatBitree(T->lchild);
		CreatBitree(T->rchild);
	}
}

bool isSameStructure(BiTree A, BiTree B)
{
	if(A == NULL && B == NULL) return true;
	if(A == NULL || B == NULL) return false;
	return isSameStructure(A->lchild, B->lchild) && isSameStructure(A->rchild, B->rchild);
}

int main()
{
	BiTree A, B;
	cout << "请输入（在空子树处添加*）二叉树  A 的先序序列：" << endl;
	CreatBitree(A);
	cout << "请输入（在空子树处添加*）二叉树  B 的先序序列：" << endl;
	CreatBitree(B);
	
	if(isSameStructure(A, B)) cout << "结构相同";
	else cout << "结构不同";
	
	return 0;
}
