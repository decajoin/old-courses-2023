#include <iostream>
#include <cmath>
using namespace std;

int c[20], n = 8, cnt = 0;  // c数组用于存储每行皇后所在的列编号，n表示棋盘大小，cnt用于计数解的数量

void print() 
{
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < n; ++j) 
		{
			if (j == c[i]) cout << "# ";  // 打印皇后的位置
			else cout << ". ";  // 打印空白位置
		}
		cout << endl;
	}
	cout << endl;
}

bool isSafe(int row, int col) 
{
	for (int i = 0; i < row; ++i) 
	{
		// 检查同一列是否有皇后
		if (c[i] == col) return false;
		
		// 检查对角线是否有皇后
		if (abs(i - row) == abs(c[i] - col)) return false;
	}
	return true;  // 如果当前位置安全，返回true，否则返回false
}

void search(int r)
{
	if (r == n)  // 找到了一种解决方案
	{
		print();  // 打印解决方案
		cnt++;    // 增加解的计数
		return;
	}
	
	for (int i = 0; i < n; ++i) 
	{
		if (isSafe(r, i)) {  // 如果当前位置安全
			c[r] = i;        // 在当前行的当前列放置皇后
			search(r + 1);   // 递归进入下一行
		}
	}
}

int main() 
{
	search(0);  // 从第一行开始搜索解决方案
	cout << "八皇后问题共有: " << cnt << "种解法!" << endl;
	return 0;
}

