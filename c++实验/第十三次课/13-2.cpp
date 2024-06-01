#include <iostream>

using namespace std;


template <class T>
T Max(T value[], int size) {
	T maxVal = value[0];
	for (int i = 1; i < size; ++i) {
		if (value[i] > maxVal) {
			maxVal = value[i];
		}
	}
	return maxVal;
}

int main() {
	// 整数数组
	int intArray[] = {1, 5, 3, 8, 2};
	int intSize = sizeof(intArray) / sizeof(intArray[0]);
	
	// 双精度浮点数数组
	double doubleArray[] = {3.14, 2.718, 1.618, 0.99, 4.20};
	int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
	
	// 求解整数数组中的最大值
	int maxInt = Max(intArray, intSize);
	cout << "最大整数值: " << maxInt << endl;
	
	// 求解双精度浮点数数组中的最大值
	double maxDouble = Max(doubleArray, doubleSize);
	cout << "最大双精度浮点数值: " << maxDouble << endl;
	
	return 0;
}

