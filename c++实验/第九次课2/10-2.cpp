#include <iostream>
using namespace std;

class Employee {
private:
	int number; // 工号
	string name; // 姓名
	
public:
	double salary; // 月薪
	
	string getName() {
		return name;
	}
	
	// 基类构造函数
	Employee(int num, string sname) : number(num), name(sname) {};
};

class Salesman : public Employee {
private:
	double commrate; // 提成率
	double sales; // 月销售额
	
public:
	// 派生类构造函数
	Salesman(int num, string sname, double com, double sale) : Employee(num, sname), commrate(com), sales(sale) {
		salary = 3000; // Salesman底薪为3000
	};
	
	void pay() {
		salary = salary + sales * commrate; // 计算销售员工的月薪
	}
	
	void print() {
		cout << "Salesman-" << getName() << "月薪是:" << salary << endl; // 输出销售员工的月薪
	}
};

class Salesmanager : public Employee {
private:
	double sales; // 月销售额
	
public:
	// 派生类构造函数
	Salesmanager(int num, string sname, double sale) : Employee(num, sname), sales(sale) {
		salary = 6000; // Salesmanager底薪为6000
	};
	
	void pay() {
		salary = salary + sales * 20.0 / 1000; // 计算销售经理的月薪
	}
	
	void print() {
		cout << "Salesmanager-" << getName() << "月薪是:" << salary << endl; // 输出销售经理的月薪
	}
};

int main() {
	// 创建销售员工和销售经理对象
	Salesman s1(321, "Tom", 5.0 / 1000, 1000000);
	s1.pay();
	s1.print();
	
	Salesman s2(322, "Jerry", 5.0 / 1000, 2000000);
	s2.pay();
	s2.print();
	
	Salesmanager sm1(123, "Chris", 1000000);
	sm1.pay();
	sm1.print();
	
	Salesmanager sm2(124, "Dannies", 2000000);
	sm2.pay();
	sm2.print();
	
	return 0;
}
