#include <iostream>
using namespace std;

const int N = 1e5+7;
int n, v, s, dp[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> dp[s++];
	for (int i = 1; i < n; i++) {
		cin >> v;
		if (v < dp[s-1]) {
			dp[s++] = v;
		} else {
			int l = 0, r = s-1;
			while (l < r) {
				int m = (l + r) >> 1;
				if (dp[m] <= v) {
					r = m;
				} else {
					l = m+1;
				}
			}
			dp[r] = v;
		}
	}
	//
	cout << s << "\n";
	return 0;
}
