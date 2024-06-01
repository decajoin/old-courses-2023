#include<iostream>
#include<string.h>
#define INF 0x3fffffff
using namespace std;
const int MAXN = 10;
int score[MAXN];
int main()
{
	int sum = 0,cnt = 0;
	for(int i = 0;i < 10;i++) 
	{
		scanf("%d",score + i);
		sum += *(score + i);
	}
	double mean = sum/10.0;
	
	for(int i = 0;i < 10;i++)
	{
		if(*(score + i) > mean) cnt++;
	}
	
	printf("%lf\n",mean);
	printf("%d",cnt);
 	return 0;
}

