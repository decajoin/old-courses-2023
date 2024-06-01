#include <iostream>
#include <string>
using namespace std;


class A{
	int i;
protected:
	char c;
public:
	string s;
	
	void show(){cout<<"A::i="<<i<<"  A::c="<<c<<"  A::s="<<s<<endl;}
	A(int tempai, char tempac, string tempas) : i(tempai), c(tempac), s(tempas){};
};


class B{
	int i;
protected:
	char c;
public:
	string s;
	
	void show(){cout<<"B::i="<<i<<"  B::c="<<c<<"  B::s="<<s<<endl;}
	B(int tempbi, char tempbc, string tempbs) : i(tempbi), c(tempbc), s(tempbs){};
};


class C: public A, public B{
public:
	C(int tempai, char tempac, string tempas, int tempbi, char tempbc, string tempbs):A(tempai,tempac,tempas), B(tempbi,tempbc,tempbs){};
};


int main(){
	
	C c(1,'a', "as", 2, 'b', "bs");  
	c.A::show();  
	c.B::show();
	
	
	return 0;
}

