#include <iostream>
#include <string>
using namespace std;

class Course {
public:
	int cno;
	string cname;
	
	// 构造函数
	Course(int tempcno, string tempcname) : cno(tempcno), cname(tempcname) {}
	
	void course_show() {
		cout << "课程号: " << cno << " 课程名: " << cname << endl;
	}
};

class Score {
private:
	int score;
	
public:
	// 构造函数
	Score(int tempscore) : score(tempscore) {}
	
	// 拷贝构造函数
	Score(const Score &tempss) : score(tempss.score) {}
	
	void score_show() {
		cout << "分数: " << score << endl;
	}
};

class Student {
private:
	int sno;
	string sname;
	string gender;
	string grade;
	Course sc;
	Score ss;
	
public:
	// 构造函数，初始化学生信息
	Student(int tempsno, string tempsname, string tempgender, string tempgrade, Course tempsc, Score tempss)
	: sno(tempsno), sname(tempsname), gender(tempgender), grade(tempgrade), sc(tempsc), ss(tempss) {}
	
	// 显示学生信息
	void student_show() {
		cout << "学号: " << sno << " 姓名: " << sname << " 性别: " << gender << " 班级: " << grade << endl;
		cout << "所选课程信息:" << endl;
		sc.course_show();
		cout << "成绩信息:" << endl;
		ss.score_show();
	}
};

int main() {
	Course cs1(19218120, "C++");
	Score sc1(90);
	Student st1(201811219, "张三", "男", "计科161", cs1, sc1);
	st1.student_show();
	
	return 0;
}

