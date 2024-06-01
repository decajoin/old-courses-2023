#include<iostream>
#include"mystack2.h"

using namespace std;

void PrintStack(LinkStack S)
{
	while(S != NULL)
	{
		cout << S->data;
		S = S->next;
	}
	cout << endl;
}

int main()
{
	LinkStack S;
	InitStack(S);
	int n;
	cin >> n;
	
	while(n != 0)
	{
		push(S,n % 8);
		n /= 8;
	}
	
	PrintStack(S);
	return 0;
}
