#include <iostream>

using namespace std;

int cube_fuc(int i)
{
	return i * i * i;
}

bool judge_fuc(int i)
{
	int num[3];
	// 取数
	num[0] = i / 100;
	num[1] = i % 100 / 10;
	num[2] = i % 100 % 10;
	return (i == cube_fuc(num[0]) + cube_fuc(num[1]) + cube_fuc(num[2]));
}

int main()
{
	cout << "1000以内水仙花数有:" << endl;
	for (int i = 100; i < 1000; i++)
	{
		if (judge_fuc(i)) cout << i << endl;
	}

	return 0;
}
