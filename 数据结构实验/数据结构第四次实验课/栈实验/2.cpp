#include<iostream>
#include"mystack2.h"
using namespace std;

int main()
{
	LinkStack S;
	InitStack(S);
	int n;
	int e;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		int x;
		cin >> x;
		push(S,x);
	}
	
	cin >> n;
	for(int i = 0;i < n;i++) pop(S,e);
	
	if(StackEmpty(S)) cout << "Y";
	else cout << "N";
	
	if(!StackEmpty(S))
	{
		top(S,e);
		cout << endl;
		cout << e << endl;
		
		travel(S);	
	}
	return 0;
}
