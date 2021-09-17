#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18 + 6.9;
bool maximize(ll& a, ll b) {
	return a < b ? a = b, 1 : 0;
}
const int maxN = 1e6 + 69;
struct max2 {
	ll m1 = -INF, m2 = -INF;
	void add(ll v) {
		if (v > m1) m2 = m1, m1 = v;
		else if (v > m2) m2 = v;
	}
};
int n;
ll w[maxN];
vector<int> adj[maxN];

int node;
ll depth[maxN];
ll par[maxN];

ll diameter;
ll mid_depth;
ll midpoint;

ll sz_w[maxN];
ll maxdep[maxN];
ll dp[maxN][2];

void dfs(int u, int p) {
	depth[u] = depth[p] + 1;
	par[u] = p;
	if (depth[u] > depth[node]) node = u;
	for (int& v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
}
void init() {
	node = 0;
	dfs(1, 1);
	int u = node;
	depth[node] = 0;
	dfs(node, node);
	int v = node;
	diameter = depth[v];
	mid_depth = (depth[v] + 1) / 2;
	while (depth[v] > mid_depth) v = par[v];
	midpoint = v;
}
void dfs2(int u, int p) {
	if (u == p) depth[u] = 0;
	else depth[u] = depth[p] + 1;
	sz_w[u] = w[u];
	maxdep[u] = depth[u];
	for (int& v : adj[u]) {
		if (v == p) continue;
		dfs2(v, u);
		sz_w[u] += sz_w[v];
		maximize(maxdep[u], maxdep[v]);
	}
	dp[u][0] = dp[u][1] = 0;
	for (int& v : adj[u]) {
		if (v == p) continue;
		if (maxdep[v] == diameter - mid_depth)
			maximize(dp[u][0], dp[v][0] + (sz_w[u] - sz_w[v]) * (mid_depth + depth[u]));
		if (maxdep[v] == mid_depth - 1)
			maximize(dp[u][1], dp[v][1] + (sz_w[u] - sz_w[v]) * (mid_depth - depth[u]));
	}
	if (depth[u] == maxdep[u] && depth[u] == diameter - mid_depth)
		maximize(dp[u][0], w[u] * (mid_depth + depth[u]));
	if (depth[u] == maxdep[u] && depth[u] == mid_depth - 1)
		maximize(dp[u][1], w[u] * (mid_depth - depth[u]));
}
ll solve() {
	dfs2(midpoint, midpoint);

	max2 dec;
	for (int& v : adj[midpoint]) {
		if (maxdep[v] != mid_depth - 1) continue;
		dec.add(dp[v][1] - sz_w[v] * mid_depth);
	}
	ll res = 0;
	for (int& v : adj[midpoint]) {
		if (maxdep[v] != diameter - mid_depth) continue;
		ll cur = sz_w[midpoint] * mid_depth;
		cur += dp[v][0] - sz_w[v] * mid_depth;

		ll fun = diameter % 2 == 1 ? dp[v][1] - sz_w[v] * mid_depth : INF;
		if (dec.m1 != fun) cur += dec.m1;
		else cur += dec.m2;
		maximize(res, cur);
	}
	return res;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1, u, v; i <= n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (n == 2) return cout << max(w[1], w[2]) * 2 + min(w[1], w[2]), 0;

	init();

	ll ans = solve();
	if (diameter % 2 == 0) {
		mid_depth++;
		maximize(ans, solve());
	}
	cout << ans;

}
