
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 14 14:16:39 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <bits/stdc++.h>
using namespace std;

#define vector2 = vector<vector<int>>

struct edge {
	int u, v;
};

const int N = 3e5+7;
int n, typ[N];
int last1, last2;
int res;

edge ed[N];
vector<int> adj[N];

bool has(set<int> &s, int i) {
	return s.find(i) != s.end();
}

// mỗi đồ thị con sẽ là độc nhất
// vì nó là cây mà

bool dfs(int u, int p, int a, int b, set<int> &s) {
	bool found = false;
	for (int v: adj[u]) if (v != p && typ[v] != b) {
		if (dfs(v, u, a, b, s)) {
			found = true;
			s.insert(v);
		}
	}
	return found || typ[u] == a;
}

set<int> path(int a, int b, int first) {
	set<int> s;
	s.insert(first);
	dfs(first, -1, a, b, s);
	return s;
}

bool travel(int u, int des, int p, vector<int> &way) {
	if (u == des) return true;
	for (int v: adj[u]) if (v != p) {
		if (travel(v, des, u, way)) {
			way.push_back(v);
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> typ[i];
		if (typ[i] == 1) last1 = i;
		if (typ[i] == 2) last2 = i;
	}
	for (int i = 0; i < n-1; i++) {
		cin >> ed[i].u >> ed[i].v;
		ed[i].u--;
		ed[i].v--;
		//
		adj[ed[i].u].push_back(ed[i].v);
		adj[ed[i].v].push_back(ed[i].u);
	}
	//
	set<int> f = path(1, 2, last1);	// các đỉnh của đồ thị con chỉ có 0 và 1
	set<int> g = path(2, 1, last2);	// các đỉnh của đồ thị con chỉ có 0 và 2
	// giữa hai điểm bất kỳ chỉ có 1 đường đi
	// --> cho đi từ last 1 đến last 2
	vector<int> way;
	travel(last1, last2, -1, way);
	way.push_back(last1);
	//
	res = way.size()-1;
	for (int i = 0; i < way.size() - 1; i++) {
		int u = way[i], v = way[i+1];
		if (has(f, u) && has(f, v)) res--;
		if (has(g, u) && has(g, v)) res--;
	}
	cout << res << "\n";
	return 0;
}

