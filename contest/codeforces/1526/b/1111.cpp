#include <iostream>
using namespace std;

// two state: 11 (2-digits) and 111(3-digits)
// 11a + 111b + 1111c + 11111d + 111111e
// = 11a + 111b + (11*100 + 11)c + (111*100 + 11)d + (111*1000 + 111)e
// = 11(a + 100c + c + d) + 111(b + 100d + 1000e + e)
// = 11k + 111r

bool calc(int n) {
	int k = n % 11;
	int r = n - k*111;
	return r >= 0 && r % 11 == 0;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (calc(n)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	//
	return 0;
}
