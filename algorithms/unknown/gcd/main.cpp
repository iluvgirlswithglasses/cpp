#include <iostream>
using namespace std;

// a = bq + r
// a % c == 0 && b % c == 0 --> r % c == 0
// --> euclid gcd
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	cout << gcd(36, 48);
	//
	getchar();
	return 0;
}
