#include <iostream>
#include <vector>
using namespace std;

#define pi pair<int, int>
#define st first
#define nd second
const int N = 1e5+7;
const int R = 1e9+7;

int n, w[N];
vector<int> adj[N];

pi dfs(int u, int p) {
	pi cr = {w[u], 0};	// {choose u, discard u}
	for (int &v: adj[u]) if (v != p) {
		pi child = dfs(v, u);
		cr.st += child.nd;	// choose this, discard child
		cr.nd += max(child.st, child.nd);	// discard this, choose or discard child
		cr.st %= R; cr.nd %= R;
	}
	return cr;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << dfs(0, -1).st << "\n";
	return 0;
}
