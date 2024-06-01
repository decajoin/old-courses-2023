#include <iostream>
#include <string>
using namespace std;
class GrandFather {
private:
	int  CardID;
	void showCardID() { cout << "GrandFather::CardID=" << CardID << endl; }
protected:
	int Age;
	void showAge() { cout << "GrandFather::Age=" << Age << endl; }
public:
	string Name;
	void showName()
{
	cout << "GrandFather::Name=" << Name << endl;
}
	GrandFather(string name, int age, int cardid):Name(name),Age(age),CardID(cardid){}
	void showGrandFatherCardID(){showCardID();}    //预留的显示GrandFather类中CardID信息的接口；
};
class Father :public GrandFather {
private:
	int CardID;
	void showCardID() { cout << "Father::CardID=" << CardID << endl; }
protected:
	int Age;
	void showAge() { cout << "Father::Age=" << Age << endl; }
public:
	string Name;
	void showName()
{cout << "Father::Name=" << Name << endl;}
	Father(string name1,int age1,int cardid1, string name2, int age2, int cardid2) :GrandFather(name1,age1,cardid1),Name(name2), Age(age2), CardID(cardid2) {}
	void showGrandFatherCardIDinFather(){showGrandFatherCardID();}  //Father类中用于显示GrandFather类的CardID信息的接口；
	void showFatherCardID(){showCardID();}                          //预留的显示Father类中CardID信息的接口；
};
class Child :public Father {
private:
	int CardID;
	void showCardID() { cout << "Child::CardID=" << CardID << endl; }
protected:
	int Age;
	void showAge() { cout << "Child::Age=" << Age << endl; }
public:
	string Name;
	void showName()
{cout << "Child::Name=" << Name << endl;}
	Child(string name1,int age1,int cardid1,string name2,int age2,int cardid2,string name3,int age3,int cardid3  ) :Father(name1, age1,cardid1,name2,age2,cardid2), Name(name3), Age(age3), CardID(cardid3) {}
	void showGrandFatherCardIDinChild(){showGrandFatherCardIDinFather();}//Child类中用于显示GrandFather类的CardID信息的接口；
	void showFatherCardIDinChild(){showFatherCardID();}//预留的显示Child类中CardID信息的接口；
};
int main() {
	//以下代码为验证同名覆盖机制和局部优先原则；
	GrandFather g("GrandFather", 70, 123);
	g.showName();
	//g.showAge();
	//g.showCardID();
	Father f("GrandFather", 70, 123, "Father", 40, 456);
	f.showName();
	//f.showAge();
	//f.showCardID();
	Child c("GrandFather", 70, 123, "Father", 40, 456, "Child", 10, 789);
	c.showName();
	//c.showAge();
	//c.showCardID();
	
	//以下代码为验证支配规则（即作用域规则）；
	f.GrandFather::showName();
	c.GrandFather::showName();
	c.Father::showName();
	
	//以下代码为验证最近优先原则（需要注释掉Child类中的showName()成员函数）；
	c.showName();
	
	return 0;
}
