#include<iostream>
#include<string.h>
using namespace std;
typedef struct Student_{
	int num;
	int socre;
}Student;

typedef struct Node_{
	Student stu;
	struct Node_* next;
}Node;

void inputStudent(Node* head)
{
	Node* move = head;
	while(move->next != NULL) move = move->next;
	
	Node* fresh = (Node*)malloc(sizeof(Node));
	fresh->next = NULL;
	
	printf("请输入学生学号:");
	scanf("%d",&fresh->stu.num);
	printf("\n请输入学生成绩:");
	scanf("%d",&fresh->stu.socre);
	
	move->next = fresh;
}

void printStudent(Node* head)
{
	Node* move = head->next;
	int flag = 0;
	while(move != NULL)
	{
		printf("学号为%d的学生成绩是%d\n",move->stu.num,move->stu.socre);
		move = move->next;
		flag = 1;
	}
	if(!flag) printf("无学生信息\n");
}

int main()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;

	while(1)
	{
		printf("插入 --- 1\n");
		printf("打印 --- 2\n");
		int cns;
		scanf("%d",&cns);
		switch (cns)
		{
			case 1 : inputStudent(head); break;
			case 2 : printStudent(head); break;
		}
	}
 	return 0;
}

