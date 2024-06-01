#include <iostream>
using namespace std;

class BaseClass{
public:
	virtual void fn(int x){ cout << "In BaseClass, int x=" << x << endl; }
};

class SubClass : public BaseClass{
public:
	void fn(int x){ cout << "In SubClass, float x=" << x << endl; }
};

void test(BaseClass& b){ int i = 1;   b.fn(i);   float f = 2.0;   b.fn(f); }

int main()
{
	BaseClass bc;    SubClass sc;
	cout << "Calling test(bc)\n";    test(bc);
	cout << "Calling test(sc)\n";    test(sc);

	system("pause");
	return 0;
}
