#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q; cin >> q;
	while (q--) {
		int n, d; cin >> n >> d;
		int s = 0;
		for (int i = 0; i < n; i++) {
			int a; cin >> a; s += a;
		}
		//
		double average = (double) s / n;
		double tmp = 1.0;
		int highest = ceil(average), lowest = floor(average);
		if (modf(average, &tmp) > 0.5) lowest = ceil(average);
		//
		if (highest + lowest <= d) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
