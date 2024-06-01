#include<iostream>
#include<string.h>
using namespace std;

typedef struct Student_{
	int num;
	string sex;
	string name;
	string place;
}Student;

int main()
{
	Student S;
	S.name = "Tim";
	S.place = "南京";
	S.sex = "男";
	S.num = 16;
	
	cout<< "姓名：" << S.name << endl;
	cout<< "学号：" << S.num << endl;
	cout<< "地址：" << S.place << endl;
	cout<< "性别：" << S.sex << endl;
	
 	return 0;
}
