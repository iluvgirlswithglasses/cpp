#include <iostream>
using namespace std;

typedef long long int lli;
lli k = 2050;	// i'll store the protagonist here

// perfs
lli recursion(lli & n) {
	// used to be recursion
	// but not anymore
	//
	lli cr = 205;	// loop optimization
	for (int i = 0; i < 16; i++) {
		if (cr * 10 > n) {
			lli res = n / cr;
			n %= cr;
			return res;
		}
		cr *= 10;
	}
	// this should never happen
	return -1;
}

lli calc(lli n) {
	// since n must == sum(k.1e?)
	if (n % k != 0) return -1;
	//
	lli counts = 0;
	//
	while (n != 0) counts += recursion(n);
	//
	return counts;
}

// drivers
int main() {
	int t; cin >> t;
	// java bracket style goes brrrr
	while (t--) {
		lli n; cin >> n;
		cout << calc(n) << endl;
	}
	//
	return 0;
}
