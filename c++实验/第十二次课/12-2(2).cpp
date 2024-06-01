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
	
	A(int i, char c, const string& s) : i(i), c(c), s(s) {}
	
	void show() {
		cout << "A::i = " << i << ", A::c = " << c << ", A::s = " << s << endl;
	}
};

class B : virtual public A {
public:
	B(int i, char c, const string& s) : A(i, c, s) {}
};

class C : virtual public A {
public:
	C(int i, char c, const string& s) : A(i, c, s) {}
};

class D : public B, public C {
public:
	D(int iB, char cB, const string& sB, int iC, char cC, const string& sC) : A(iB, cB, sB), B(iB, cB, sB), C(iC, cC, sC) {}
};

int main() {
	D d(98, 'b', "bs", 99, 'c', "cs");
	
	d.B::show();  // 显示通过类B的路径访问A的数据成员
	d.C::show();  // 显示通过类C的路径访问A的数据成员
	d.show();     // 显示直接通过类D访问A的数据成员
	
	cout << "使用虚继承方式解决路径二义性时，派生类对象所占空间大小为：" << sizeof(d) << endl;
	
	return 0;
}

