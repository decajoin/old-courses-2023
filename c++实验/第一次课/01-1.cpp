#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	bool flag = false;
	cout << "100以内的所有素数:" << endl;
	for (int i = 2; i <= 100; i++)
	{
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				flag = true;
				break;
			}
		}
		if (!flag) cout << i << " ";
		flag = false;
	}
	return 0;
}
