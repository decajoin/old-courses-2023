#include <iostream>

using namespace std;

template <typename T>
T add(T a, T b) {
	return a + b;
}

// 类模板
template <typename T>
class Pair {
private:
	T first;
	T second;
	
public:
	Pair(T f, T s) : first(f), second(s) {}
	
	void display() {
		cout << "Pair: (" << first << ", " << second << ")\n";
	}
};


int main() {
	// 测试函数模板
	cout << "Testing Function Template:\n";
	int result1 = add(5, 10);
	double result2 = add(3.5, 2.5);
	cout << "Result 1: " << result1 << endl;
	cout << "Result 2: " << result2 << endl;
	
	// 测试类模板
	cout << "\nTesting Class Template:\n";
	Pair<int> intPair(1, 2);
	Pair<double> doublePair(3.5, 2.5);
	
	cout << "Integer Pair: ";
	intPair.display();
	
	cout << "Double Pair: ";
	doublePair.display();
	
	return 0;
}
