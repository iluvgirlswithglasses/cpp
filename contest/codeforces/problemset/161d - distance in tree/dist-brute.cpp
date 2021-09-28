#include <iostream>
#include <vector>
using namespace std;

#define u64 unsigned long long
#define u16 unsigned short

const u16 N = 5e4+7, K = 502;
u16 n, k;
u64 res, cnt[N];
vector<u16> adj[N];

void dfs(int u, int p, int l) {
	if (l == k) {
		cnt[u]++;
	} else {
		for (u16 &v: adj[u]) if (v != p) {
			dfs(v, u, l+1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		dfs(i, -1, 0);
	for (int i = 0; i < n; i++) 
		res += cnt[i];
	//
	cout << (res >> 1) << "\n";
	return 0;
}
