#include <iostream>
using namespace std;


class Figure{
	int sidenum;
public:
	Figure(){cout<<"Figure."<<endl;}
	Figure(int temp):sidenum(temp){cout<<"The figure has "<<sidenum<<" sides."<<endl;};
};


class Quadrangle1: virtual public Figure{
public:
	Quadrangle1(){cout<<"Quadrangle1."<<endl;}
};


class Parallelogram: virtual public Figure{
public:
	Parallelogram(){cout<<"Parallelogram."<<endl;}
};


class Quadrangle2: virtual public Figure{
public:
	Quadrangle2(){cout<<"Quadrangle2."<<endl;}
};


class Rhombus: virtual public Quadrangle1, virtual public Parallelogram{
protected:
	int sidelength;
public:
	Rhombus(){cout<<"Rhombus."<<endl;}
	Rhombus(int t2):sidelength(t2){
		cout<<"This is a rhombus."<<endl;
	};
};


class Rectangle: virtual public Quadrangle2, virtual public Parallelogram{
protected:
	int angle;
public:
	Rectangle(){cout<<"Rectangle."<<endl;}
	Rectangle(int t3) : angle(t3) {};
};


class Square: public Rhombus, public Rectangle
{
public:
	Square(){cout<<"Square."<<endl;}
	// 全虚继承需要在最后的子类中完成对第一个基类的构造（Figure）
	Square(int t1, int t2, int t3) :Figure(t1), Rhombus(t2), Rectangle(t3){
	cout<<"The figure is a square!"<<endl<<"All angles of the square are "<<angle<<" degrees."<<
	endl<<"The sidelength of the square is "<<sidelength<<"."<<endl<<"The area of the square is "
	<<sidelength*sidelength<<endl; 
	};
};


int main(){	
	
	Square s(4,10,90);    

	return 0;
}

