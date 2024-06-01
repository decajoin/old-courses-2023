/*
(1) 先计算括号内，后计算括号外；
(2) 在无括号或同层括号内，先乘除运算，后加减运算，即乘除运算的优先级高于加减运算的优先级；
(3) 同一优先级运算，从左向右依次进行。
*/
#include<iostream>
#include<string.h>
#include"mystack2.h"

using namespace std;
const int MAXN = 1e5 + 10;
char s[MAXN];


int main()
{
	LinkStack numStack;
	LinkStackS operatorStack;
	
	InitStack(numStack);
	InitStackS(operatorStack);
	
	int n = 0;
	scanf("%s",s);
	int lenght = strlen(s);

	for(int i = 0;i < lenght;i++)
	{
		if(s[i] >= '0' && s[i] <= '9')	// 将数字处理压栈 
		{
			n = s[i] - '0';
			while(i < lenght)
			{
				if(s[i + 1] >= '0' && s[i] <= '9')
				{
					n = n*10 + (s[i + 1] - '0');
					i++;
				}
				else break;
			}
			push(numStack,n);
		}
		else if(s[i] == '+' || s[i] =='-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')')	// 处理算术符 
		{
			char e;
			topS(operatorStack,e);			
			switch(s[i])
			{
				case '+' :
				{
					if(e != '+' && e != '-' && e != '*' && e != '/')
					{
						pushS(operatorStack,'+');
					}
					else
					{
						while(!StackEmptyS(operatorStack) && e != '(')
						{
							popS(operatorStack,e);
							calculate(numStack,e);
							topS(operatorStack,e);
						}
						pushS(operatorStack,'+');
					}
				}
				break;
				case '-' :
				{
					if(e != '+' && e != '-' && e != '*' && e != '/')
					{
						pushS(operatorStack,'-');
					}
					else
					{
						while(!StackEmptyS(operatorStack) && e != '(')
						{
							popS(operatorStack,e);
							calculate(numStack,e);
							topS(operatorStack,e);
						}
						pushS(operatorStack,'-');						
					}
				}
				break;
				case '*' :
				{
					if(e != '*' && e != '/')
					{
						pushS(operatorStack,'*');
					}
					else
					{
						while(!StackEmptyS(operatorStack) && e != '(')
						{
							popS(operatorStack,e);
							calculate(numStack,e);
							topS(operatorStack,e);
						}
						pushS(operatorStack,'*');							
					}					
				}
				break;
				case '/' :
				{
					if(e != '*' && e != '/')
					{
						pushS(operatorStack,'/');
					}
					else
					{
						while(!StackEmptyS(operatorStack) && e != '(')
						{
							popS(operatorStack,e);
							calculate(numStack,e);
							topS(operatorStack,e);
						}
						pushS(operatorStack,'/');							
					}					
				}					
				break;
				case '(' :
				{
					pushS(operatorStack,'(');
				}
				break;
				case ')' :
				{
					while(e != '(')
					{
						popS(operatorStack,e);
						calculate(numStack,e);	
						topS(operatorStack,e);					
					}
					popS(operatorStack,e);
				}
				break;
			}
		}
	}
	
	char x;
	while(!StackEmptyS(operatorStack)) 
	{
		popS(operatorStack,x);
		calculate(numStack,x);
	}
	
	int ans;
	top(numStack,ans);
	cout << ans;
}
