#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct bitnode {
    char data;                  //数据域
    struct bitnode* lchild, * rchild;  //左右孩子指针域
}BiTNode, * BiTree;

void CreateBiTree(BiTree& T)
{
    char a;
    cin >> a;
    if (a == '*') T = NULL;
    else
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = a;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}


int DeepthBiTree(BiTree T)
{
    if (T == NULL) return 0;
    else
    {
        int dL = DeepthBiTree(T->lchild);
        int dR = DeepthBiTree(T->rchild);
        return 1 + (dL > dR ? dL : dR);
    }
    
}

int main()
{
    BiTree T;
    CreateBiTree(T);

    cout << "二叉树的深度为：" << DeepthBiTree(T);

	return 0;
}