#include<iostream>
#include<string.h>
using namespace std;
void swap1(int* a,int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap2(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a,b;
	int *sa,*sb;
	sa = &a;
	sb = &b;
	scanf("%d%d",sa,sb);
	swap1(sa,sb);
	//swap2(a,b);
	printf("%d %d",a,b);
 	return 0;
}
