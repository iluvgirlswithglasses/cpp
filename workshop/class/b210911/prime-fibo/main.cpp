#include <iostream>
using namespace std;

int n = 1000000;

// FIXME
// improve me please
bool is_prime(int a) {
	// there is no number has division greater than it self / 2
	// since it will not a prime if it % 2 == 0,
	// i < a / 2 has the same effect as i <= a / 2
	for (int i = 2; i < a / 2; i++) {
		if (a % i == 0) return false;
	}
	return true;
}

int main() {
	int c = 0;
	//
	int col[2] = {1, 1};
	while (col[1] < n) {
		if (is_prime(col[1])) c += 1;
		// new fibo num
		int cr = col[0] + col[1];
		// shifting ~~
		col[0] = col[1];
		col[1] = cr;
	}
	cout << c;
	//
	getchar();
	return 0;
}
