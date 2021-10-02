#include <iostream>
using namespace std;

const int N = 1e5+7, I = 1e9+7;
int n, k, a[N], dp[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	//
	for (int i = 1; i < n; i++) {
		int p = I;
		for (int j = max(i-k, 0); j < i; j++)
			p = min(p, dp[j] + abs(a[i] - a[j]));
		dp[i] = p;
	}
	cout << dp[n-1] << "\n";
	return 0;
}
