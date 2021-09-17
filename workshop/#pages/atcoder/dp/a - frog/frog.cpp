#include <iostream>
using namespace std;

const int N = 1e5+7, I = 1e9+7;
int n, a[N], dp[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	//
	for (int i = 2; i <= n; i++) {
		dp[i] = min(
			abs(a[i] - a[i-2]) + dp[i-2],
			abs(a[i] - a[i-1]) + dp[i-1]
		);
	}
	cout << dp[n] << "\n";
	return 0;
}
