#include<iostream>
#include<cstring>


using namespace std;

// 交换字符串函数
void swap (string &a, string &b)
{
	string temp;
	temp = a;
	a = b;
	b = temp;
}


// 字符串排序函数
void fuc (string str[])
{
	// 冒泡排序
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			int len = min(str[j].length(), str[j + 1].length());
			bool flag = false;
			// 考虑字符串长度不同的情况
			for (int k = 0; k < len; k++)
			{
				if (str[j][k] > str[j + 1][k]) 
				{
					swap(str[j], str[j + 1]);
					flag = true;
					break;
				}
				else if (str[j][k] < str[j + 1][k]) break;
			}
			if (!flag && str[j].length() > str[j + 1].length())
			{
				swap(str[j], str[j + 1]);
			}
		}
	}
}

int main()
{
	string str[5];
	
	cout << "请输入五个字符串:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> str[i];
	}
	
	fuc(str);
	
	cout << "排序好的字符串如下所示:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << str[i] << endl;
	}
	return 0;
}
