#include <iostream>
using namespace std;


class baseclass{
public:
	virtual baseclass* afn() { cout << "This is Baseclass.\n"; return this; }
};

class subclass : public baseclass{
public:
	subclass* afn(){ cout << "This is Subclass.\n";  return this; }
};

void test(baseclass& x){
	x.afn();
}

int main(){
	baseclass bc;   subclass sc;   test(bc);   test(sc);


	system("pause");
	return 0;
}

