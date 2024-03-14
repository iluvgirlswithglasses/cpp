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
	return a[l] == v;
}

//     a[r] - a[m] == a[m] - a[l-1]
// --> 2a[m] == a[r] + a[l-1]
int calc() {
	for (int len = n; len >= 2; len--) {
		for (int l = 1; l <= n - len + 1; l++) {
			int r = l + len - 1;
			int s = a[r] + a[l-1];
			//
			if (s & 1) continue;
			if (find(l, r, s>>1)) {
				return len;
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
