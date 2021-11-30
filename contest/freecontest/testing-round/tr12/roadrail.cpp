
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Nov 30 09:59:00 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

/** @vars */
const int N = 2e5+7;
int n, m, l;
// grp_m[u]: group của đỉnh u trong đg bộ
// grp_l[u]: group của đỉnh u của đg sắt
int grp_m[N], grp_l[N];
// cnt[i][j]: số đỉnh u có grp_m[u] == i & grp_l[u] == j
map<int, int> cnt[N];

/** @dfs */
void dfs(int u, int g, int* grp, vector<bool>& visited, vector<vector<int>>& adj) {
	visited[u] = true;
	grp[u] = g;
	//
	for (int v: adj[u]) if (!visited[v]) {
		dfs(v, g, grp, visited, adj);
	}
}

/** @drivers */
int read(int m, int* grp) {
	vector<vector<int>> adj(n);
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//
	int group = 0;
	vector<bool> visited(n, false);
	for (int i = 0; i < n; i++) if (!visited[i]) {
		dfs(i, group, grp, visited, adj);
		group++;
	}
	return group;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> l;
	m = read(m, grp_m);
	l = read(l, grp_l);
	for (int u = 0; u < n; u++)
		cnt[ grp_m[u] ][ grp_l[u] ]++;
	//
	for (int u = 0; u < n; u++)
		cout << cnt[ grp_m[u] ][ grp_l[u] ] << " ";
	cout << "\n";
	return 0;
}
