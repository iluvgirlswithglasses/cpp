
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Aug 13 00:41:45 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// https://vnoi.info/wiki/algo/data-structures/heavy-light-decomposition.md

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e5+7;
int n;
vector<int> adj[N];
int parent[N];
// childCnt[i]: the largest line of vertices that `i` can be the root of
int childCnt[N];

// calculate childCnt
int dfs(int u) {
	if (adj[u].size() == 0) return 1;
	int mx = 0;
	for (int v: adj[u]) {
		int r = dfs(v);
		if (r > mx) mx = r;
	}
	childCnt[u] = mx;
	return mx + 1;
}

// implement any kind of segtree you want here
struct SegTree {
	int f[N<<1];

	void upd(int l, int r, int v) {
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) l++;
			if (r&1) --r;
		}
	}

	int get(int i) {
		for (i += n; i > 0; i >>= 1) {
			
		}
		return -1;
	}
} segtree;

struct HLD {
	int crChain = 0;	// latest chain
	int head[N];		// head[i]: the first vertice of chain `i`
	int chain[N];		// chain[i]: the chain that vertice `i` belongs to 
	int crIndex = 0;
	int index[N];		// index[i]: index of vertice `i` in flatten tree

	void init(int u) {
		// if this vertice is the head of a new chain
		if (head[crChain] == 0) head[crChain] = u;
		//
		chain[u] = crChain;
		index[u] = crIndex++;
		// find heavy vertice
		int mx = -1;
		for (int v: adj[u]) if (mx == -1 || childCnt[v] > childCnt[mx]) {
			mx = v;
		}
		if (mx > -1) init(mx);
		// after the procession of the heavy vertice
		// make another chain
		for (int v: adj[u]) if (v != mx) {
			crChain++;
			init(v);
		}
	}
} hld;

void debug() {
	for (int i = 0; i <= n; i++)
		cout << hld.
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// inp
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		parent[v] = u;
	}
	// pre-calculation
	dfs(1);
	hld.init(1);
	// queries and updates
	// returns
	debug();
	return 0;
}
