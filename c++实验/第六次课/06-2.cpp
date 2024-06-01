#include <iostream>
using namespace std;

class LineList {
private:
	float* List;
	int Max;
	int Num;
	
public:
	// 构造函数，动态分配初始空间，初始化成员变量
	LineList(int n = 10) {
		List = new float[n];
		Max = n;
		Num = 0;
	}
	
	// 析构函数，释放动态分配的内存
	~LineList() {
		delete[] List;
	}
	
	// 在线性表尾部增加一个元素
	void Add(float x) {
		if (Num < Max) {
			List[Num++] = x;
		} else {
			// 分配新空间
			float* NewList = new float[Max + 5];
			// 将List拷贝到NewList
			for (int i = 0; i < Num; i++) {
				NewList[i] = List[i];
			}
			// 删除List
			delete[] List;
			Max += 5;
			// 改回原名
			List = NewList;
			List[Num++] = x;
		}
	}
	
	// 输出所有元素
	void OutPut() {
		for (int i = 0; i < Num; i++) {
			cout << List[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	LineList myList(5); // 初始化一个最大容量为5的线性表
	
	myList.Add(3);
	myList.Add(20);
	myList.Add(5);
	myList.Add(6);
	myList.Add(7);
	
	cout << "线性表的元素为：" << endl;
	myList.OutPut();
	
	myList.Add(666); // 超过最大容量，会动态扩展空间
	
	cout << "扩容后线性表的元素为：" << endl;
	myList.OutPut();
	
	return 0;
}

