#include <iostream>
#include <ctype.h>
void move(int num, int x, int y, int z);

using namespace std;

int main(){
	int h;
	char flag;
	
	while(tolower(flag)!='n')  
	{
		cout << "汉诺塔问题" << endl << "Please input the number of the diskes: ";
		cin >> h;
		cout << "The steps to moving " << h << " diskes are as follows:" << endl;
		move(h,1,2,3);
		cout << endl << "Do you want to go on?(y for yes, n for no) ";
		cin >> flag;
	}
}
void move(int num, int x, int y, int z){
	// 直接将一个盘子从 x 移动到 z
	if(num == 1) cout << x << "-->" << z << '\t';
	else  
	{
		// 将 num-1 个盘子从 x 经由 z 移动到 y
		move(num - 1, x, z, y);
		// 将 num-1 个盘子从 x 经由 z 移动到 y
		cout << x << "-->" << z << '\t';
		// 将 num-1 个盘子从 y 经由 x 移动到 z
		move(num - 1, y, x, z);
	}
}

