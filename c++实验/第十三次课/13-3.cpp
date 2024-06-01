#include <iostream>

using namespace std;

template <class T1, class T2, class T3>
class OutPut {
	T1 data1;
	T2 data2;
	T3 data3;
	
public:
	OutPut(T1 x, T2 y, T3 z) : data1(x), data2(y), data3(z) {}
	
	void Display() {
		cout << "数据1: " << data1 << ", 数据2: " << data2 << ", 数据3: " << data3 << endl;
	}
	
	// 重载函数，实现不同类型数据的输出
	void Display(T1 t1) {
		cout << "使用重载函数实现数据的输出：" << t1 << endl;
	}
};

int main() {
	// 实例化模板类，包含整型、浮点型、字符型数据
	OutPut<int, double, char> obj1(1, 2.5, 'A');
	
	// 调用 Display 函数显示模板类的数据
	cout << "显示模板类的数据：" << endl;
	obj1.Display();
	
	// 调用重载函数显示特定类型的数据
	obj1.Display(211);
	
	return 0;
}

