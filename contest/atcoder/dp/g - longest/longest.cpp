#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5+7;
int n, m, dp[N];
vector<bool> visited(N, false);
vector<int> adj[N];

void dfs(int u) {
	visited[u] = true;
	int pre = dp[u];
	for (int v: adj[u]) {
		if (!visited[v]) dfs(v);
		dp[u] = max(dp[u], pre + dp[v] + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[--u].push_back(--v);
	}
	for (int i = 0; i < n; i++)
		if (!visited[i]) dfs(i);
	cout << *max_element(dp, dp+n) << "\n";
	return 0;
}
