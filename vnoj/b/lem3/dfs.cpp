#include <iostream>
using namespace std;

const int N = 16, I = 2e9+7;
int n, m[N][N], dp[1<<N][N];

// v: visited[], bitset version
// so that we can retrieve data from dp directly
int dfs(int v, int src) {
	if (v == 0) 
		return 0;
	int &res = dp[v][src];
	if (res == 0) {
		res = I;
		for (int i = 0; i < n; i++) if (v>>i&1) {
			res = min(
				res, 
				dfs(v & ~(1<<i), i) + m[i][src]
			);
		}
	}
	return res;
}

int calc() {
	int res = I;
	for (int i = 0; i < n; i++) {
		res = min(res, dfs((1<<n)-1, i));
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> m[i][j];
	//
	cout << calc() << "\n";
	return 0;
}
