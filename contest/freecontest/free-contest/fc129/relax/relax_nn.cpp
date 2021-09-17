#include <iostream>
using namespace std;

// A == B --> A ^ B == 0
const int N = 3e5+4;
int n, a[N], acc[N];	// acc[i] = sum_xor(a, a+i)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long res = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		acc[i] = acc[i-1] ^ a[i];
	}
	//
	for (int l = 1; l <= n - 1; l++) {
		for (int r = l + 1; r <= n; r+=2) {
			// int m = r - l + 1; if (m & 1) continue;
			int m = (l + r - 1) >> 1;
			// if (acc[m]^acc[l-1]^acc[r]^acc[m] == 0) res++;
			int c = acc[l-1]^acc[r];
			if (c == 0) {
				res++;
			}
		}
	}
	cout << res << endl;
	return 0;
}
