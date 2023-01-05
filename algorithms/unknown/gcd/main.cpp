#include <iostream>
using namespace std;

// a = bq + r
// a % c == 0 && b % c == 0 --> r % c == 0
// --> euclid gcd
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int iterative_gcd(int a, int b) {
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	while (true) {
		int a, b; cin >> a >> b;
		cout << iterative_gcd(a, b) << "\n";
	}
	return 0;
}
