#include<iostream>

using namespace std;

// 求阶乘的小函数
// 题目要求1-20阶乘和没超过long long范围
long long fuc (int x)
{
	long long ans;
	for (int i = 2; i <= x; i++)
	{
		ans = ans * i;
	}
	return ans;
}

int main()
{
	long long ans;
	for (int i = 1; i <= 20; i++)
	{
		ans += fuc(i);
	}
	cout << "1～20的阶乘之和:" << endl;
	cout << ans;
	return 0;
}
