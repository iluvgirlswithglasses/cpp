#include <iostream>
using namespace std;

const int N = 5007;
int n, a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; a[i] += a[i-1];
	}
	//
	for (int i = n; i >= 2; i--) {
		bool can_break = false;
		//
		for (int k = 1; k < i; k++) {
			int right_sum = a[i] - a[k];
			//
			int v = a[k] - right_sum, l = 1, r = k;
			while (l < r) {
				int m = (l + r + 1) >> 1;
				if (a[m] <= v) {
					l = m;
				} else {
					r = m - 1;
				}
			}
			//
			if (right_sum == a[k] - a[l]) {
				res = i - l;
				can_break = true;
				break;
			}
		}
		//
		if (can_break) break;
	}
	cout << res << endl;
	return 0;
}
