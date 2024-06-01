#include<iostream>
#include<string.h>
#define INF 0x3fffffff
using namespace std;

typedef struct Student_{
	int num;
	char name[10];
	int score[3];
}Student;

void inputStudent(Student stu[])
{
	for(int i = 0;i < 5;i++)
	{
		printf("请分别输入学生的学号，姓名，三门课分数");
		scanf("%d%s%d%d%d",&stu[i].num,&stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
	}
}

void meanStudent(Student stu[])
{
	int sum[3];
	memset(sum,0,sizeof(sum));
	for(int i = 0;i < 3;i++)
	{
		for(int j = 0;j < 5;j++)
		{
			sum[i] += stu[j].score[i];
		}
	}
	
	for(int i = 0;i < 3;i++)
	{
		printf("%.2lf\n",sum[i]/5.0);
	}
}

void printStudent(Student stu[])
{
	int sum[5],Max = -INF,flag = -1;
	memset(sum,0,sizeof(sum));
	for(int i = 0;i < 5;i++)
	{
		for(int j = 0;j < 3;j++)
		{
			sum[i] += stu[i].score[j];
		}
		if(sum[i] > Max)
		{
			Max = sum[i];
			flag = i;
		}
	}
	printf("%d %s %d %d %d",stu[flag].num,stu[flag].name,stu[flag].score[0],stu[flag].score[1],stu[flag].score[2]);
}

int main()
{
	Student stu[5];
	
	inputStudent(stu);
	meanStudent(stu);
	printStudent(stu);
	
 	return 0;
}
