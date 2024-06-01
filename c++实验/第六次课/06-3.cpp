#include <iostream>
#include <cstring>
using namespace std;

class PhoneBook {
private:
	char name[50];
	char* Address;
	char PhoneNumber[15];
	
public:
	// 构造函数，初始化成员变量，包括动态分配地址空间
	PhoneBook(const char* n, const char* addr, const char* phone) {
		strcpy(name, n);
		Address = new char[strlen(addr) + 1];
		strcpy(Address, addr);
		strcpy(PhoneNumber, phone);
	}
	
	// 拷贝构造函数，用于复制通讯录对象
	PhoneBook(const PhoneBook& other) {
		strcpy(name, other.name);
		Address = new char[strlen(other.Address) + 1];
		strcpy(Address, other.Address);
		strcpy(PhoneNumber, other.PhoneNumber);
	}
	
	// 析构函数，释放动态分配的内存
	~PhoneBook() {
		delete[] Address;
	}
	
	// 输出通讯录信息
	void Display() {
		cout << "姓名: " << name << endl;
		cout << "地址: " << Address << endl;
		cout << "电话号码: " << PhoneNumber << endl;
	}
};

int main() {
	PhoneBook phonebook1("张三", "北京", "1335456456");
	PhoneBook phonebook2("李四", "南京", "8825476898");
	PhoneBook phonebook3("王五", "南京", "7749096575");
	
	PhoneBook phonebookCopy(phonebook1);
	
	cout << "通讯录信息：" << endl;
	phonebook1.Display();
	cout << endl;
	
	cout << "拷贝的通讯录信息：" << endl;
	phonebookCopy.Display();
	cout << endl;
	
	cout << "其他通讯录信息：" << endl;
	phonebook2.Display();
	phonebook3.Display();
	
	return 0;
}

