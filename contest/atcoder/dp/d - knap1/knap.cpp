#include <iostream>
using namespace std;

#define u64 unsigned long long

const int W = 1e5+7;
int n, m; u64 dp[W];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0, w, v; i < n; i++) {
		cin >> w >> v;
		for (int j = m; j > 0; j--) {
			int pre = j - w;
			if (pre < 0) break;
			dp[j] = max(dp[j], dp[pre] + v);
		}
	}
	cout << dp[m] << "\n";
	return 0;
}
