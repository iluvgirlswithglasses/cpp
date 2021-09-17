#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
int n, plog[N<<1];
vector<int> adj[N];

struct LCA {
	/**
	 * lca
	 * */
	vector<int> height, euler, first;
	vector<bool> visited;
	LCA() {
		height.resize(n, 0);
		first.resize(n, 0);
		euler.reserve(n<<1);
		visited.resize(n, false);
		dfs(0, 0);
		int m = euler.size();
		st_build();
	}

	void dfs(int u, int h) {
		visited[u] = true;
		height[u] = h;
		first[u] = euler.size();
		euler.push_back(u);
		for (int v: adj[u]) if (!visited[v]) {
			dfs(v, h+1);
			euler.push_back(u);
		}
	}

	int query(int u, int v) {
		int l = first[u], r = first[v];
		if (l > r) swap(l, r);
		return st_query(l, r);
	}


	/**
	 * sparse table
	 * */
	vector<vector<int>> st;
	void st_build() {
		int n = euler.size(), k = floor(plog[n]) + 1;
		st.resize(n, vector<int>(k+1));
		for (int i = 0; i < n; i++)
			st[i][0] = euler[i];
		for (int j = 1; j <= k; j++) {
			for (int i = 0; i + (1<<j) <= n; i++) {
				st[i][j] = min(
					st[i][j-1],
					st[i + (1<<(j-1))][j-1]
				);
			}
		}
	}

	int st_query(int l, int r) {
		int j = plog[r-l+1];
		return min(st[l][j], st[r - (1<<j) + 1][j]);
	}
};


/**
 * drivers
 * */
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	plog[1] = 0;
	for (int i = 2; i <= (n<<1); i++)
		plog[i] = plog[i/2]+1;
	//
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	LCA lca = LCA();
	while (true) {
		int u, v; cin >> u >> v;
		cout << lca.query(u, v) << "\n";
	}
	return 0;
}
