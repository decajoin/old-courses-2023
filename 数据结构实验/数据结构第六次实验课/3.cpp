#include<iostream>
#include<cstdlib>
#include<cstring>
#define INF 0x3fffffff
using namespace std;
const int MAXN = 1000;
int w[MAXN];

typedef struct{
	//结点的权值 
	int weight;
	//结点的双亲、左孩子、右孩子的下标 
	int parent, lchild, rchild;
	//结点的序号
	int num;
}HTNode, *HuffmanTree;
typedef char* *HuffmanCode;

int min(HuffmanTree HT,int n)
{
	int m;
	int k = INF;
	for(int i = 1;i <= n;i++)
	{
		if(HT[i].weight < k &&HT[i].parent == 0)
		{
			k = HT[i].weight;
			m = i;
		}
	}
	// m就是权值最小的结点的序号 
	HT[m].parent = 1;	// 标记该结点避免二次查找 
	return m;
}

//在HT[1…i-1]选择parent为0且weight最小的两个结点,其序号分别为s1和s2 
void Select(HuffmanTree HT, int n, int &s1, int &s2)
{
	s1 = min(HT, n);
	s2 = min(HT, n);
}


// *w是权值数组的头指针 
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{
	if(n <= 1) return;
	int m = 2 * n - 1;	//n 个叶子的Huffman树共有2n-1个结点 
	HT=(HuffmanTree)malloc((m + 1)*sizeof(HTNode));   //0单元未用，给所有的结点分配空间 
	int i;
	HuffmanTree p;
	
	// 初始化哈夫曼树  
	w++;	// w下标从1开始 
	for(p = HT + 1,i = 1; i<=n; ++i,++p,++w)	//初始化前n个单元 
	{
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
		p->weight = *w;
		p->num = i;
	}
	for(;i <= m;++i, ++p)	//对叶子之后的存储单元清零 
	{
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
		p->weight = 0;
		p->num = i;
	}
	
	//建Huffman树  
	for(i=n+1;i<=m; ++i)	  
	{
	    //在HT[1…i-1]选择parent为0且weight最小的两个结点,其序号分别为s1和s2 
		int s1, s2;
		Select(HT, i-1, s1, s2);
		HT[s1].parent=i;	HT[s2].parent=i; 
 		HT[i].lchild=s1; 	HT[i].rchild=s2;  //s1、s2分别作为i的左右孩子 
		HT[i].weight=HT[s1].weight+ HT[s2].weight;
	}	
	
	//从叶子到根逆向求每个字符的赫夫曼编码 
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));	//  分配n个字符编码的头指针 
	char* cd;
	cd = (char*)malloc(n * sizeof(char));	// 分配求编码的工作空间 
	cd[n - 1] = '\0';	//编码结束符（从cd[0]~cd[n-1]为合法空间）
	//逐个字符求Huffman编码 
	for(i=1;i<=n;++i)
	{
		int start = n-1;  //编码结束符位置 
		int c, f;
		for(c = i,f = HT[i].parent;f != 0;   c = f, f = HT[f].parent)
		{
			//从叶子到根逆向求编码 
			if(HT[f].lchild == c) cd[--start] = '0';
			else cd[--start] = '1';
			
		}
		//为第i个字符编码分配空间 
		HC[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy(HC[i], &cd[start]);	//从cd复制编码串到HC		
	}
	free(cd);	//释放工作空间 
	
}

int main()
{
	int n, x;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		w[i] = x;
	}
	
	HuffmanTree HT;
	HuffmanCode HC;
	HuffmanCoding(HT, HC, w, n);
	for(int i = 1;i <= n;i++) cout << HC[i] <<endl;
	
	return 0;
}
