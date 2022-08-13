
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Aug 13 16:17:23 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

/**
 * @vars & defs
 * */
#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e5+7;
int n;
vector<int> adj[N];
int parent[N];		// parent[i]: the parent node of `i`
int childCnt[N];	// childCnt[i]: the longest line that `i` can be the head of

/**
 * @utils
 * */
int calcChildCnt(int u, int p) {
	parent[u] = p;
	if (u != 1 && adj[u].size() == 1) return 1;
	int mx = 0;
	for (int v: adj[u]) if (v != p) {
		mx = max(mx, calcChildCnt(v, u));
	}
	childCnt[u] = mx;
	return mx + 1;
}

/**
 * @hld
 * */
struct SegTree {
	// update 1 query N
	// this SegTree handles HLD's indexes
	// f[n->2n] == 0 --> white
	// otherwise, it's the index of the node in flatten tree
	int f[N<<1];

	void init() {
		for (int i = 0; i < (n<<1); i++)
			f[i] = N;
	}

	void upd(int p) {
		if (f[p+n] == N) f[p+n] = p;	// turns to black
		else f[p+n] = N;				// turns to white
		//
		for (p = (p+n)>>1; p > 0; p >>= 1)
			f[p] = min(f[p<<1], f[p<<1|1]);
	}

	int get(int l, int r) {
		int res = N;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) res = min(res, f[l++]);
			if (r&1) res = min(res, f[--r]);
		}
		return res;
	}
} segtree;

struct HLD {
	int crChain = 0;
	int head[N];	// head[i]: the head node of chain `i`
	int chain[N];	// chain[i]: the chain that node `i` belongs to
	int crIndex = 0;
	int flat[N];	// the flatten tree
	int index[N];	// index[i]: the index of node `i` in flatten tree

	void build(int u) {
		if (head[crChain] == 0) head[crChain] = u;
		chain[u] = crChain;
		flat[crIndex] = u;
		index[u] = crIndex++;
		// lengthen the chain
		int mx = -1, mxCnt = -1;
		for (int v: adj[u]) if (v != parent[u]) {
			if (childCnt[v] > mxCnt) {
				mx = v;
				mxCnt = childCnt[v];
			}
		}
		if (mxCnt > -1) build(mx);
		// create new chains
		for (int v: adj[u]) if (v != parent[u] && v != mx) {
			crChain++;
			build(v);
		}
	}

	void upd(int u) {
		segtree.upd(index[u]);
	}

	int find(int u) {
		int res = N;
		while (true) {
			int hd = head[ chain[u] ];
			res = min(res, segtree.get(index[hd], index[u] + 1));
			if (chain[u] == chain[1])
				break;
			u = parent[hd];
		}
		return res == N ? -1 : flat[res];
	}
} hld;

/**
 * @drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// io
	int q; cin >> n >> q;
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// pre-calculations
	calcChildCnt(1, 0);
	segtree.init();
	hld.build(1);
	// queries
	while (q--) {
		int t, u; cin >> t >> u;
		if (t == 0) 
			hld.upd(u);
		else 
			cout << hld.find(u) << "\n";
	}
	return 0;
}
