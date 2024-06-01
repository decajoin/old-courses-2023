#include <iostream>
using namespace std;

class CStr1 {
private:
	string str1; // 字符串成员变量
	
public:
	// 修改字符串
	void ChangrStr(string s);
	// 显示字符串
	void ShowStr();
	// 获取字符串str1的值
	string getStr1();
	// 构造函数
	CStr1(string s) : str1(s) {};
};

class CStr2 : public CStr1 {
private:
	string str2; // 字符串成员变量
	
public:
	// 修改字符串并返回拼接结果
	string ChangrStr(string s1, string s2);
	// 显示字符串
	void ShowStr();
	// 构造函数
	CStr2(string s1, string s2) : CStr1(s1), str2(s2) {};
};

void CStr1::ChangrStr(string s) {
	str1 = s; // 修改str1的值
}

void CStr1::ShowStr() {
	cout << "CStr1中str值为: " << str1 << endl; // 输出str1的值
}

string CStr1::getStr1() {
	return str1; // 返回str1的值
}

string CStr2::ChangrStr(string s1, string s2) {
	return s1 + s2; // 返回拼接结果
}

void CStr2::ShowStr() {
	CStr1::ShowStr(); // 调用基类的ShowStr()函数
	cout << "CStr2中str值为: " << str2 << endl; // 输出str2的值
	cout << "str1和str2拼接后的值为: " << ChangrStr(getStr1(), str2) << endl; // 输出str1和str2拼接后的值
}

int main() {
	CStr1 cs1("Hello"); // 创建CStr1对象
	cs1.ShowStr(); // 显示字符串
	
	cs1.ChangrStr("你好"); // 修改字符串
	cout << "str1修改后";
	cs1.ShowStr(); // 显示修改后的字符串
	
	CStr2 cs2("Hello", "C++"); // 创建CStr2对象
	cs2.ShowStr(); // 显示字符串
	
	return 0;
}
