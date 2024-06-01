#include<iostream>
#include"myQueue1.h"
#include"mystack2.h"
using namespace std;

void Arrival(LinkStack &P, LinkQueue &Q, int n, int num, int time)
{
	// Len_P是在栈里面元素个数 
	int Len_P = StackLength(P);
	// Len_Q是在队列里面元素个数 
	int Len_Q = QueueLength(Q);
	// 压位 - 由于头文件中data是一个数据，在这里我们把num和time压位再存入栈 
	// 当时间超过10000时，压位操作失效，由于题目未给出具体范围，暂时选取10000为时间最大值 
	int comx = num * 10000 + time;
	if(Len_P < n)
	{
		push(P, comx);	// 入栈
		Len_P++;
		cout << "parking location:" << Len_P << endl;
	}
	else
	{
		EnQueue(Q, comx);	// 入队
		Len_Q++;
		cout << "sidewalk location:" << Len_Q << endl;
	}
}

void Leave(LinkStack &P, LinkQueue &Q, LinkStack &T, int n, int num,int time)
{
	// x是目标车辆在栈中位置 
	int x = StackFind(P, num);
	int e;
	if(n != -1)
	{
		for(int i = 0;i < x;i++)
		{
			pop(P, e);
			push(T ,e);
		}
		pop(P, e);
		// 对压位数据处理，提取到进入停车场的时间 
		int time1 = e - 10000 * num;
		int ans = time - time1;
		cout << "time: " << ans << " parking fees: " << ans << endl;
		for(int i = 0;i < x;i++)
		{
			pop(T, e);
			push(P, e);
		}
		int Len_Q = QueueLength(Q);
		// 只有等待队列中有车辆时才出队 
		if (Len_Q > 0)
		{
			DeQueue(Q, e);
			// 更新从队列进入栈的车的进入停车场的时间 
			int num1 = e / 10000;
			e = num1 * 10000 + time;
			push(P, e); 
		}
	}
	else cout<< "车牌号码输入错误" << endl;
	
}
int main()
{
	LinkStack P;
	LinkStack T;
	LinkQueue Q;
	InitQueue(Q);
	InitStack(P);
	InitStack(T);
	char ch;
	int n, num, time;
	
	cin >> n;
	getchar();
	
	while(1)
	{
		printf("\n  A. The Car Arrive  D. The Car Leave   E. Exit System\n");
		scanf("%c%d%d",&ch, &num, &time);
		getchar();	// 消除回车对ch值的影响 
		switch(ch) 
		{
			case 'A': Arrival(P, Q, n, num, time);  break; /*车辆到达*/
			case 'D': Leave(P, Q, T, n, num, time);    break; /*车辆离开*/
			case 'E': return 0;          /*退出主程序*/ 
			default: break;
		}
	}
	
	return 0;
}
