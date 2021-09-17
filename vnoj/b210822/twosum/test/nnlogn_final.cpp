#include <iostream>
using namespace std;

const int N = 5007;
int n, a[N];

bool find(int lo, int hi, int v) {
	int l = lo, r = hi;
	while (l < r) {
		int m = (l + r + 1) >> 1;
		if (a[m] <= v) {
			l = m;
		} else {
			r = m-1;
		}
	}
	return a[l] = v;
}

//     a[r] - a[m] == a[m] - a[l-1]
// --> 2a[m] == a[r] + a[l-1]
int calc() {
	for (int r = n; r >= 2; r--) {
		for (int l = 1; l < r; l++) {
			int s = a[r] + a[l-1];
			if (s & 1) continue;
			if (find(s>>1, l, r)) {
				return r - l + 1;
			}
		}
	}
	return 0;
}

int main() {
	// inp
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; a[i] += a[i-1];
	}
	//
	cout << calc() << endl;
	return 0;
}
