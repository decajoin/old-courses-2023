#include <iostream>
#include <list>
using namespace std;

int main()
{
	int dimn, num;
	cout << "请输入矩阵的维度：";
	cin >> dimn;
	
	list<int> matrix; // 使用std::list代替数组
	
	cout << "请输入矩阵的元素：" << endl;
	for (int i = 0; i < dimn * dimn; i++)
	{
		int element;
		cin >> element;
		matrix.push_back(element); // 将元素添加到链表末尾
	}
	
	cout << "您输入的原始矩阵是：" << endl;
	int count = 0;
	for (const int &element : matrix)
	{
		cout << element << " ";
		count++;
		if (count % dimn == 0)
			cout << endl;
	}
	
	cout << endl << "请输入要乘以矩阵的数：";
	cin >> num;
	
	cout << "矩阵乘以该数后的结果是：" << endl;
	count = 0;
	for (int &element : matrix)
	{
		element *= num; // 乘以输入的数
		cout << element << " ";
		count++;
		if (count % dimn == 0)
			cout << endl;
	}
	
	cout << endl;
}

