#include <iostream>
using namespace std;

const int N = 3e5+4, I = (1 << 20) + 4;
int n, s, dp[2][I];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	//
	long long res = 0;
	dp[1][0] = 1;
	for (int i = 0; i < n; i++) {
		int v; cin >> v; s ^= v;
		res += dp[i%2][s];
		dp[i%2][s]++;
	}
	//
	cout << res << endl;
	return 0;
}
