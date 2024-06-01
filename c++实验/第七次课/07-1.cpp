#include <iostream>
using namespace std;

class Box {
private:
	int length;
	int width;
	int height;
	
public:
	// 默认构造函数
	Box() {
		length = 0;
		width = 0;
		height = 0;
	}
	
	// 构造函数，初始化数据成员
	Box(int l, int w, int h) : length(l), width(w), height(h) {}
	
	// 重载构造函数，提供多种初始化方式
	Box(int s) : length(s), width(s), height(s) {}
	
	// 拷贝构造函数，初始化一个新对象，大小为原对象的2倍
	Box(const Box &other) : length(other.length * 2), width(other.width * 2), height(other.height * 2) {}
	
	// 重载拷贝构造函数，初始化一个新对象，大小为两个对象的和
	Box(const Box &box1, const Box &box2) : length(box1.length + box2.length), width(box1.width + box2.width), height(box1.height + box2.height) {}
	
	// 计算周长
	int compute_perimeter() {
		return 4 * (length + width + height);
	}
	
	// 计算表面积
	int compute_area() {
		return 2 * (length * width + width * height + height * length);
	}
	
	// 计算体积
	int compute_volume() {
		return length * width * height;
	}
};

int main() {
	int l, w, h;
	char flag = 'y';
	while (flag == 'y') {
		cout << "请输入盒子的长度、宽度和高度: ";
		cin >> l >> w >> h;
		Box b1(l, w, h);
		
		cout << "盒子的周长是: " << b1.compute_perimeter() << endl;
		cout << "盒子的表面积是: " << b1.compute_area() << endl;
		cout << "盒子的体积是: " << b1.compute_volume() << endl;
		
		Box b2(b1);
		cout << "用原盒子的两倍尺寸初始化的新盒子的周长、表面积和体积如下:" << endl;
		cout << "周长: " << b2.compute_perimeter() << endl;
		cout << "表面积: " << b2.compute_area() << endl;
		cout << "体积: " << b2.compute_volume() << endl;
		
		Box b3(b1, b2);
		cout << "用两个盒子尺寸之和初始化的新盒子的周长、表面积和体积如下:" << endl;
		cout << "周长: " << b3.compute_perimeter() << endl;
		cout << "表面积: " << b3.compute_area() << endl;
		cout << "体积: " << b3.compute_volume() << endl;
		
		cout << "是否继续计算盒子的属性数据(y或n)？ ";
		cin >> flag;
	}
	
	return 0;
}

