#include<iostream>
using namespace std;
class lation{
	int  x,y;
public:
	lation(int t1, int t2) {
		x = t1, y = t2;
	}
	lation &operator+(const lation& t) {
		lation f(x + t.x, y+ t.y);
		return f;
	}
	friend lation operator-(const lation& t1,const lation& t2);
	friend ostream& operator<<(ostream& out, lation& p);
};
lation operator-(const lation& t1,const lation &t2) {
	lation f(t1.x - t2.x, t1.y - t2.y);
	return f;
}
ostream& operator<<(ostream& out,lation& p) {
	out << p.x << " " << p.y; return out;
}
int main() {
	lation a(1, 2); lation b(5, 6);
	lation c(0, 0); c = a + b;
	cout << c<<endl;
	c = a - b;
	cout << c << endl;
}