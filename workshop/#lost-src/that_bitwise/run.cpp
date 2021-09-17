#include <iostream>
using namespace std;

#define u64 unsigned long long

u64 f(int x) {
	if (x <= 1) return x;
	if (x&1) return f(x^1)+1;
	return f(x>>1);
}

u64 g(int x) {
	int r = 0;
	while (x > 0) {
		r++;
		x -= x&-x;
	}
	return r;
}

int main() {
	int i; cin >> i;
	cout << f(i) << " " << g(i) << " " << __builtin_popcount(i) << "\n";
	return 0;
}
