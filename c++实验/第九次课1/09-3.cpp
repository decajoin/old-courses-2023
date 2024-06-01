#include <iostream>
#include <string>
using namespace std;
const int SNUM = 2;
const int TNUM = 2;
const int ANUM = 2;

class Person {
protected:
	string name, gender;
	int age;
	
public:
	Person() {}
	Person(string tname, string tgender, int tage) : name(tname), gender(tgender), age(tage) {}
};

class Student : public Person {
protected:
	int sno;
	string major;
	
public:
	Student() {}
	Student(string tname, string tgender, int tage, int tsno, string tmajor)
	: Person(tname, tgender, tage), sno(tsno), major(tmajor) {
		cout << "一个学生注册完成" << endl;
	}
	
	void ShowStudent() {
		cout << "学号: " << sno << " 姓名: " << name << " 性别: " << gender << " 年龄: " << age << " 专业: " << major << endl;
	}
	
	
	~Student(){cout << "The Student is unconstructed!" << endl;}
};

class Teacher : public Person {
protected:
	int tno;
	string college;
	
public:
	Teacher() {}
	Teacher(string tname, string tgender, int tage, int ttno, string tcollege)
	: Person(tname, tgender, tage), tno(ttno), college(tcollege) {
		cout << "一个老师注册完成" << endl;
	}
	
	void ShowTeacher() {
		cout << "工号: " << tno << " 姓名: " << name << " 性别: " << gender << " 年龄: " << age << " 学院: " << college << endl;
	}
	
	
	~Teacher(){cout << "The Teacher is unconstructed!" << endl;}
};

class Administrator : public Person {
protected:
	int ano;
	string section;
	
public:
	Administrator() {}
	Administrator(string tname, string tgender, int tage, int tano, string tsection)
	: Person(tname, tgender, tage), ano(tano), section(tsection) {
		cout << "一个管理注册完成" << endl;
	}
	
	void ShowAdministrator() {
		cout << "工号: " << ano << " 姓名: " << name << " 性别: " << gender << " 年龄: " << age << " 部门: " << section << endl;
	}
	
	~Administrator(){cout << "The Administrator is unconstructed!" << endl;}
};

class University {
	string uname, uaddress;
	Student s[SNUM];
	Teacher t[TNUM];
	Administrator a[ANUM];
	
public:
	University() {}
	
	void TermBegin() {
		cout << "请输入大学的名称和地址: ";
		cin >> uname >> uaddress;
		int i;
		
		cout << "请按照如下格式输入" << SNUM << "个学生的信息:" << endl;
		cout << "(学号 姓名 性别 年龄 专业)" << endl;
		for (i = 0; i < SNUM; i++) {
			int sno;
			string sname, sgender, smajor;
			int sage;
			cin >> sno >> sname >> sgender >> sage >> smajor;
			s[i] = Student(sname, sgender, sage, sno, smajor);
		}
		
		cout << "请按照如下格式输入" << TNUM << "个老师的信息:" << endl;
		cout << "(工号 姓名 性别 年龄 学院)" << endl;
		for (i = 0; i < TNUM; i++) {
			int tno;
			string tname, tgender, tcollege;
			int tage;
			cin >> tno >> tname >> tgender >> tage >> tcollege;
			t[i] = Teacher(tname, tgender, tage, tno, tcollege);
		}
		
		cout << "请按照如下格式输入" << ANUM << "个管理的信息:" << endl;
		cout << "(工号 姓名 性别 年龄 部门)" << endl;
		for (i = 0; i < ANUM; i++) {
			int ano;
			string aname, agender, asection;
			int aage;
			cin >> ano >> aname >> agender >> aage >> asection;
			a[i] = Administrator(aname, agender, aage, ano, asection);
		}
	}
	
	void ShowUniversity() {
		cout << "该大学的基本信息显示如下:" << endl
		<< uname << "  " << uaddress << endl;
		
		int i;
		cout << "该大学的学生信息显示如下:" << endl;
		for (i = 0; i < SNUM; i++) {
			s[i].ShowStudent();
		}
		
		cout << "该大学的老师信息显示如下:" << endl;
		for (i = 0; i < TNUM; i++) {
			t[i].ShowTeacher();
		}
		
		cout << "该大学的管理信息显示如下:" << endl;
		for (i = 0; i < ANUM; i++) {
			a[i].ShowAdministrator();
		}
	}
};

int main() {
	University u;
	u.TermBegin();
	u.ShowUniversity();
	
	return 0;
}

