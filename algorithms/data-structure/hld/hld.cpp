
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

/*
sample problem:
	given a tree and 3 kinds of queries:
		1. mod u v x:
			modify the value of every nodes on the path from `u` to `v` by `x`
		2. get u
			print the value of node `u`
		3. lca u v
			print the lca of nodes `u` and `v`
	every node has the value of 0 in the beginning
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
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

// need this to complete the given problem
struct LCA {

	struct SegTree {
		int n;
		pi f[N<<2];	// f[i]: {index, depth}

		void build(vector<int>& euler, vector<int>& depth) {
			n = euler.size();
			for (int i = 0; i < n; i++) {
				f[i+n] = make_pair(euler[i], depth[euler[i]]);
			}
			for (int i = n-1; i > 0; i--) {
				if (f[i<<1].nd < f[i<<1|1].nd)
					f[i] = f[i<<1];
				else
					f[i] = f[i<<1|1];
			}
		}

		int get(int l, int r) {
			int res = -1, mn = 2e9;
			for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
				if (l&1) {
					if (f[l].nd < mn) res = f[l].st, mn = f[l].nd;
					l++;
				}
				if (r&1) {
					r--;
					if (f[r].nd < mn) res = f[r].st, mn = f[r].nd;
				}
			}
			return res;
		}
	} segtree;

	vector<int> euler, first, depth;

	void init() {
		euler.reserve(n<<1);
		first.resize(n+1);
		depth.resize(n+1);
		dfs(1, 0);
		segtree.build(euler, depth);
	}

	void dfs(int u, int d) {
		first[u] = euler.size();
		depth[u] = d;
		euler.push_back(u);
		for (int v: adj[u]) {
			dfs(v, d+1);
			euler.push_back(u);
		}
	}

	int get(int u, int v) {
		if (first[u] > first[v]) swap(u, v);
		return segtree.get(first[u], first[v]+1);
	}

} lca;


// heavy light decomposition implementation
struct HLD {

	struct SegTree {
		int f[N<<1];

		void upd(int l, int r, int v) {
			for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
				if (l&1) f[l++] += v;
				if (r&1) f[--r] += v;
			}
		}

		int get(int i) {
			int res = 0;
			for (i += n; i > 0; i >>= 1) {
				res += f[i];
			}
			return res;
		}
	} segtree;

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

	// this supports the bellowing update(int, int, int) function
	// a stands for lca(u, v)
	void linear_update(int u, int a, int x) {
		int cnt = 0;
		while (true) {
			if (chain[u] == chain[a]) {
				segtree.upd(index[a], index[u]+1, x);
				break;
			} else {
				int hd = head[ chain[u] ];
				segtree.upd(index[hd], index[u]+1, x);
				u = parent[hd];
			}
		}
	}

	void update(int u, int v, int x) {
		int a = lca.get(u, v);
		linear_update(u, a, x);
		linear_update(v, a, x);
		// lca(u, v) is overlapped
		segtree.upd(index[a], index[a]+1, -x);
	}

	int query(int u) {
		return segtree.get(index[u]);
	}

} hld;

void debug() {

}

void execute_queries() {
	int q; cin >> q;
	while (q--) {
		string t; cin >> t;
		if (t == "mod") {
			int u, v, x; cin >> u >> v >> x;
			hld.update(u, v, x);
		} else if (t == "get") {
			int u; cin >> u;
			cout << hld.query(u) << "\n";
		} else if (t == "lca") {
			int u, v; cin >> u >> v;
			cout << lca.get(u, v) << "\n";
		}
	}
}

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	// inp
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		parent[v] = u;
	}
	// pre-calculation
	dfs(1);
	lca.init();
	hld.init(1);
	debug();
	//
	execute_queries();
	return 0;
}
