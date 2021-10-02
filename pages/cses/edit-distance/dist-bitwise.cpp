#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 5e3+7;
int n, m, dp[2][N];
string s, t;

int calc() {
	for (int i = 0; i <= m; i++) 
		dp[0][i] = i, dp[1][i] = i;
	//
	for (int i = 1; i <= n; i++) {
		dp[i&1][0] = i; 
		for (int j = 1; j <= m; j++) {
			// f[j]: tối thiểu để biến t[0:j] thành s[0:i]
			if (s[i-1] == t[j-1]) {
				dp[i&1][j] = dp[i&1^1][j-1];
			} else {
				int a[] = {dp[i&1^1][j], dp[i&1^1][j-1], dp[i&1][j-1]};
				dp[i&1][j] = 1 + *min_element(a, a+3);
			}
		}
	}
	return dp[n&1][m];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s >> t;
	n = s.length(), m = t.length();
	cout << calc() << "\n";
	return 0;
}
