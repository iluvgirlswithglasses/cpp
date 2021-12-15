
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Dec 15 18:45:47 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @ defs & vars
 * */
struct node {
	int v, c;

	node(int _v, int _c) {
		v = _v, c = _c;
	}
};

#define pi pair<int, int>
#define st first
#define nd second
const int N = 502;

int n, k;
vector<node> adj[N];

/**
 * @ perf
 * */
void dfs(int u, int p, int dis, int cnt, vector<int>& res) {
	if (dis >= k)
		res.push_back(cnt);
	for (node& i: adj[u]) if (i.v != p) {
		dfs(i.v, u, dis + i.c, cnt + 1, res);
	}
}

int start(int u) {
	vector<int> res;	// contains all the possible results
	dfs(u, -1, 0, 0, res);
	int cnt = N;
	for (int i: res)
		cnt = min(cnt, i);
	return cnt;
}

/**
 * @ drivers
 * */
int main() {
	freopen("MARATHON.INP", "r", stdin);
	freopen("MARATHON.OUT", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n-1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[--u].push_back(node(--v, c));
		adj[v].push_back(node(u, c));
	}
	//
	int res = N;
	for (int i = 0; i < n; i++) {
		// brute ~
		res = min(res, start(i));
	}
	if (res == N) res = -1;
	cout << res << "\n";
	return 0;
}

