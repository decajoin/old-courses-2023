#include<iostream>
#include<string.h>
#define INF 0x3fffffff
using namespace std;
int a[1000];
int find_a(int n,int a[])
{
	int Max = -INF;
	int num;
	for(int i = 0;i < n;i++)
	{
		if(*(a + i) > Max)
		{
			Max = *(a + i);
			num = i;
		}
	}
	return num;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++) scanf("%d",a + i);
	cout<<find_a(n,a);
 	return 0;
}

