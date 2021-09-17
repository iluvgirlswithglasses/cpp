#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q; cin >> q;
	while (q--) {
		int n, d; cin >> n >> d;
		long long s = 0;
		for (int i = 0; i < n; i++) {
			int a; cin >> a; s += a;
		}
		//
		for (int i = 0; i < n; i+=2) {
			s -= d;
			if (s <= 0) {
				break;
			}
		}
		if (s <= 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
