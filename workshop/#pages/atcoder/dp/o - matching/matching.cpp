#include <iostream>
#include <vector>
using namespace std;

#define u32 unsigned int
const u32 N = 22, R = 1e9+7;
u32 n, dp[1<<N];
vector<bool> a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		a[i].resize(n);
		for (int j = 0, v; j < n; j++) {
			cin >> v;
			a[i][j] = v;
		}
	}
	//
	dp[0] = 1;
	for (u32 mk = 0; mk < (1<<n); mk++) {
		// matching the `i` boy
		u32 i = __builtin_popcount(mk);
		for (u32 j = 0; j < n; j++) {
			// match the `j` girl to the `i` boy
			if (!(mk>>j&1) && a[i][j]) {
				// `t`: target - the result after applying more one pair in the bitset
				u32 t = mk^(1<<j);
				dp[t] = (dp[t] + dp[mk]) % R;
			}
		}
	}
	cout << dp[(1<<n)-1] << "\n";
	return 0;
}

