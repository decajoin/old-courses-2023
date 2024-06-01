#include <iostream>
#include <vector>

using namespace std;

int main() {
	const int limit = 100;
	vector<bool> isPrime(limit + 1, true);
	
	cout << "100以内的所有素数:" << endl;
	// 埃拉托斯特尼筛法
	for (int i = 2; i <= limit; i++) {
		if (isPrime[i]) {
			cout << i << " ";
			for (int j = i * i; j <= limit; j += i) {
				isPrime[j] = false;
			}
		}
	}
	
	return 0;
}

