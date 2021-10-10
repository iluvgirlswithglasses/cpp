#include <iostream>
using namespace std;

//
bool calc() {
	int a, b, d; cin >> a >> b >> d;
	// ensure that a will always be greater than b
	if (a < b) {
		a ^= b; b ^= a; a ^= b;
	}
	// with each b in a bag, there will be at most k a in the same bag
	double pre_k = (double) a / (double) b;
	int k = pre_k;
	if (pre_k > k) k += 1;
	// a - b <= d
	return k - 1 <= d;
}

int main() {
	int t; cin >> t;
	while (t--) {
		if (calc()) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}
	//
	return 0;
}
