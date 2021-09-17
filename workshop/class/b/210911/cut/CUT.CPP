
/*
sources:
	Antti Laaksonen - Guide to Competitive Programming
	https://codeforces.com/blog/entry/8219
	Newplayers12-senpai
hardest dp problem of my life, so far
*/

#include <fstream>
using namespace std;

const int N = 2007, I = 1e9+7;
//     a[i]:	sum(1, i);
// dp[i][j]:	best result of [i:j]
// op[i][j]:	the optimal k such that dp[i][k-1] + dp[k][j] gives the best result
int n, a[N], dp[N][N], op[N][N];

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream cin("CUT.INP"); ofstream cout("CUT.OUT");
	//
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = a[i-1] + a[i];
	}
	//
	for (int i = 1; i <= n; i++)
		dp[i][i] = 0, op[i][i] = i;
	//
	for (int len = 2; len <= n; len++) {
		for (int i = 1, j = i+len-1; j <= n; i++, j++) {
			dp[i][j] = I;
			for (int k = op[i][j-1]; k <= op[i+1][j]; k++) {
				//
				int r = a[j] - a[i-1] +	dp[i][k-1] + dp[k][j];
				if (r < dp[i][j])
					dp[i][j] = r, op[i][j] = k;
			}
		}
	}
	//
	cout << dp[1][n] << "\n";
	return 0;
}
