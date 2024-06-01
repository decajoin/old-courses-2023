#include <iostream>
using namespace std;

class CBase{
private:
	int x;
	void showx() {cout<<"CBase::x="<<x<<endl;}
protected:
	int y;
	void showy() {cout<<"CBase::y="<<y<<endl;}
public:
	int z;
	void showz() {cout<<"CBase::z="<<z<<endl;}
	
	void showbasex() {showx();}
	
	// 父类初始化
	CBase(int tx, int ty, int tz) : x(tx), y(ty), z(tz){};
};
class CDeriveA:private CBase{
private:
	int ax;
	void showax() {showbasex();cout<<"CDeriveA::ax="<<ax<<endl;}
protected:
	int ay;
	void showay() {showy();cout<<"CDeriveA::ay="<<ay<<endl;}
public:
	int az;
	void showaz() {showz();cout<<"CDeriveA::az="<<az<<endl;}
	
	void showAxandBasexfromOuterA() {
		showax();
	}
	void showAyandBaseyfromOuterA() {
		showay();
	}
	
	// 子类初始化的时候必须对父类进行初始化
	CDeriveA(int tx, int ty, int tz, int ttx, int tty, int ttz) : 
	CBase(tx, ty, tz), ax(ttx), ay(tty), az(ttz){};
};
class CDeriveB:protected CBase{
private:
	int bx;
	void showbx(){showbasex();cout<<"CDeriveB::bx="<<bx<<endl;}
protected:
	int by;
	void showby(){showy();cout<<"CDeriveB::by="<<by<<endl;}
public:
	int bz;
	void showbz(){showz();cout<<"CDeriveB::bz="<<bz<<endl;}
	
	void showBxandBasexfromOuterB() {
		showbx();
	}
	void showByandBaseyfromOuterB() {
		showby();
	}
	
	CDeriveB(int tx, int ty, int tz, int ttx, int tty, int ttz) : 
	CBase(tx, ty, tz), bx(ttx), by(tty), bz(ttz){};
	
};
class CDeriveC:public CBase{
private:
	int cx;
	void showcx(){showbasex();cout<<"CDeriveC::cx="<<cx<<endl;}
protected:
	int cy;
	void showcy(){showy();cout<<"CDeriveC::cy="<<cy<<endl;}
public:
	int cz;
	void showcz(){cout << "CDeriveC::cz=" << cz << endl;}
	
	void showCxandBasexfromOuterC(){showcx();}
	void showCyandBaseyfromOuterC(){showcy();}
	
	CDeriveC(int tx, int ty, int tz, int ttx, int tty, int ttz) : 
	CBase(tx, ty, tz), cx(ttx), cy(tty), cz(ttz){};
};
int main(){
	CDeriveA ca(11,12,13,14,15,16);
	ca.showAxandBasexfromOuterA();
	ca.showAyandBaseyfromOuterA();
	ca.showaz();
	
	CDeriveB cb(21,22,23,24,25,26);
	cb.showBxandBasexfromOuterB();
	cb.showByandBaseyfromOuterB();
	cb.showbz();
	
	CDeriveC cc(31,32,33,34,35,36);
	cc.showCxandBasexfromOuterC();
	cc.showCyandBaseyfromOuterC();
	// public继承可以直接调用父类public函数
	cc.showz();
	cc.showcz();
	
	
	return 0;
}

