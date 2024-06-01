#include <iostream>
using namespace std;

class Set {
private:
	int a[10];
	
public:
	// 构造函数，用于初始化集合
	Set(int b[]) {
		for (int i = 0; i < 10; i++) {
			a[i] = b[i];
		}
	}
	
	// 输出成员函数，每行输出5个数
	void OutPut() {
		for (int i = 0; i < 10; i++) {
			cout << a[i] << " ";
			if ((i + 1) % 5 == 0) {
				cout << endl;
			}
		}
	}
	
	// 判断一个数是否在数组中的函数，返回下标值，如果不在数组中返回-1
	int Find(int x) {
		for (int i = 0; i < 10; i++) {
			if (a[i] == x) {
				return i;
			}
		}
		return -1;
	}
};

int main() {
	int testData[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
	Set mySet(testData);
	
	cout << "集合中的元素为：" << endl;
	mySet.OutPut();
	
	int numberToFind = 7; 
	int index = mySet.Find(numberToFind);
	if (index != -1) {
		cout << numberToFind << " 在集合中，位于下标 " << index << " 处。" << endl;
	} else {
		cout << numberToFind << " 不在集合中。" << endl;
	}
	
	return 0;
}

