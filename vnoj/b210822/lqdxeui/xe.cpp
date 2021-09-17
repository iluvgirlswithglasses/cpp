/*
Có 3 trường hợp:

Xuất phát từ rìa đường kính: 
	1 xe đi
	Chi phí = 2 * (đường) - (đường kính)

Xuất phát từ giữa đường kính:
	2 xe đi 2 hướng
	Chi phí = 2 * (đường) - (đường kính)

Xuất phát ngoài đường kính (trong cây thì mọi đỉnh là rìa):
	Cùng đi vào đường kính rồi ủi
	Chi phí = 2 * (đường) - (đường kính)

Đó là ý tưởng, còn lại tự tưởng tượng ;)
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5+7;
int n, dp[N];
vector<pair<int, int>> adj[N];

void dfs(int u, int p) {
	for (pair<int, int> i: adj[u]) {
		int v = i.first, t = i.second;
		if (v == p) continue;
		dp[v] = dp[u] + t;
		dfs(v, u);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int s = 0;
	// inp
	cin >> n; int dummy; cin >> dummy;
	for (int i = 0; i < n-1; i++) {
		int u, v, t;
		cin >> u >> v >> t; u--; v--;
		s += t;
		adj[u].push_back({v, t});
		adj[v].push_back({u, t});
	}
	//
	dfs(0, -1);
	int d_pole = distance(dp, max_element(dp, dp+n));	// d == diameter
	//
	dp[d_pole] = 0;
	dfs(d_pole, -1);
	int d_len = *max_element(dp, dp+n);
	cout << (s<<1) - d_len << endl;
	return 0;
}
