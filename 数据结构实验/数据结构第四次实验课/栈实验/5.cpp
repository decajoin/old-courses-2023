#include<iostream>

using namespace std;

int n = 1;
void move(char a,int n,char b)
{
	cout << n << ":" << " ";
	cout << n << " " << a << " " << b <<endl;
	n++;
}

void hanoi(int n,char x,char y,char z)
{
	if(n == 1) move(x,1,z);	// 将编号为1的圆盘从x移到z 
	else
	{
		hanoi(n - 1,x,z,y);	// 将x上编号为1到n-1的圆盘移到y，z作辅助塔  
		move(x,n,z);		// 将编号为n的圆盘从x移到z 
		hanoi(n - 1,y,x,z);	// 将y上编号为1到n-1的圆盘移到z，x作辅助塔 
	}
}

int main()
{
	int n;
	cin >> n;
	hanoi(n,'A','B','C');
	return 0;
}
