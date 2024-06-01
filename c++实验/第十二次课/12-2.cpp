#include <iostream>
#include <string>
using namespace std;

class A {
private:
	int i;
	
protected:
	char c;
	
public:
	string s;
	
	A(int temp_i, char temp_c, string temp_s) : i(temp_i), c(temp_c), s(temp_s) {}
	
	void show() {
		cout << "A: i = " << i << ", c = " << c << ", s = " << s << endl;
	}
};

class B : public A {
public:
	B(int temp_i, char temp_c, string temp_s) : A(temp_i, temp_c, temp_s) {}
};

class C : public A {
public:
	C(int temp_i, char temp_c, string temp_s) : A(temp_i, temp_c, temp_s) {}
};

class D : public B, public C {
public:
	D(int temp_i_B, char temp_c_B, string temp_s_B, int temp_i_C, char temp_c_C, string temp_s_C)
	: B(temp_i_B, temp_c_B, temp_s_B), C(temp_i_C, temp_c_C, temp_s_C) {}
};

int main() {
	
	D d(98, 'b', "bs", 99, 'c', "cs");
	d.B::show(); // 使用作用域规则解决路径二义性
	d.C::show(); // 使用作用域规则解决路径二义性
	cout << "使用作用域规则解决路径二义性时，派生类对象所占空间大小为：" << sizeof(d) << endl;
	
	return 0;
}

