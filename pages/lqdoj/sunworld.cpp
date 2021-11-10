
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Nov 10 16:17:07 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5+7;
int n, m, cnt;
unordered_set<int> t;	// targeted places
vector<int> adj[N];
vector<int> g[N];		// non-redundant graph

bool dfs(int u, int p) {
	bool found = false;
	for (int v: adj[u]) if (v != p) {
		if (dfs(v, u)) {
			found = true;
			g[u].push_back(v);
			g[v].push_back(u);
			cnt++;
		}
	}
	//
	return found || t.find(u) != t.end();
}

/* find diameter of the graph */
int d[N];

void d_dfs(int u, int p) {
	for (int v: g[u]) if (v != p) {		
		d[v] = d[u] + 1;
		d_dfs(v, u);
	}
}

int diameter() {
	d_dfs(*t.begin(), n);
	int edge = max_element(d, d+n) - d;
	memset(d, 0, n * sizeof(d[0]));
	d_dfs(edge, n);
	return *max_element(d, d+n);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u; cin >> u;
		t.insert(u);
	}
	//
	for (int i = 0; i < n-1; i++) {
		int u, v; 
		cin >> u >> v; 
		//
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//
	dfs(*t.begin(), -1);
	int res = (cnt<<1) - diameter();
	cout << res << "\n";
	return 0;
}

