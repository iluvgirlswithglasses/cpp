
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Aug 26 20:12:13 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// basically they ask me to upgrade every wire 
// that doesn't belong in the maximum spanning tree
// in the most confusing way possible

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @defs
 * */
#define all(c) c.begin(), c.end()
#define ll long long
const int N = 1e5+7, I = 1e6+7;

struct Edge {
	int u, v, w;

	void get() {
		cin >> u >> v >> w; 
		u--; v--;
	}
};

struct Node {
	int v, w;
};

/**
 * @vars
 * */
int n, m;
vector<Node> adj[N];	// the maximum spanning tree
vector<Edge> upgrades;	// the wires that require upgrading

/**
 * @hld
 * */
struct LCA {

	struct Segtree {
		// query(i, j): Returns the smallest depth in euler[i:j)

		int n;
		vector<pair<int, int>> f;	// f[i]: {depth, id}

		void build(vector<int> &euler, vector<int> &depth) {
			n = euler.size();
			f.resize(n<<1);
			for (int i = 0; i < n; i++)
				f[i+n] = {depth[euler[i]], euler[i]};
			for (int i = n-1; i > 0; i--)
				f[i] = min(f[i<<1], f[i<<1|1]);
		}

		int query(int l, int r) {
			pair<int, int> res = {I, -1};
			for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
				if (l&1) res = min(res, f[l++]);
				if (r&1) res = min(res, f[--r]);
			}
			return res.second;
		}
	} st;

	vector<int> euler, first, depth;

	void build() {
		euler.reserve(n<<1);
		first.resize(n);
		depth.resize(n);
		dfs(0, -1, 0);
		st.build(euler, depth);
	}

	void dfs(int u, int p, int d) {
		first[u] = euler.size();
		euler.push_back(u);
		depth.push_back(d);
		for (Node i: adj[u]) if (i.v != p) {
			dfs(i.v, u, d+1);
			euler.push_back(u);
		}
	}

	int query(int a, int b) {
		if (first[a] > first[b]) swap(a, b);
		return st.query(first[a], first[b]+1);
	}
} lca;

struct HLD {

	struct ChildManager {
		vector<int> cnt;	// cnt[i]: the number of i's child nodes
		vector<int> parent;	// parent[i]: the parent of `i`
		vector<int> weight;	// weight[i]: the weight of the edge that connect `i` and its parent

		void init() {
			cnt.resize(n, 0);
			parent.resize(n, -1);
			weight.resize(n, 0);
			dfs(0, -1);
		}

		int dfs(int u, int p) {
			if (p != -1 && adj[u].size() == 1) return 1;
			int mx = 0;
			for (Node &i: adj[u]) if (i.v != p) {
				parent[i.v] = u;
				weight[i.v] = i.w;
				mx = max(mx, dfs(i.v, u));
			}
			cnt[u] = mx;
			return mx + 1;
		}
	} mgr;

	struct SegTree {
		// query(i, j): 
		// returns the minimum weight from index `i` to `j` 
		// in the flatten tree

		vector<int> f;

		void build(vector<int> &index, vector<int> &weight) {
			f.resize(n<<1, 0);
			for (int i = 0; i < n; i++)
				// f[index of `i` in flatten tree] = weight of `i`
				f[n + index[i]] = weight[i];
			for (int i = n-1; i > 0; i--)
				f[i] = min(f[i<<1], f[i<<1|1]);
		}

		int query(int l, int r) {
			int res = I;
			for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
				if (l&1) res = min(res, f[l++]);
				if (r&1) res = min(res, f[--r]);
			}
			return res;
		}
	} st;

	int crChain = 0;
	vector<int> chain;	// chain[i]: the chain that vertice `i` belongs to
	vector<int> head;	// head[i]: the head vertice of chain `i`
	int crIndex = 0;
	vector<int> index;	// index[i]: the index of vertice `i` in the flatten tree

	void build() {
		chain.resize(n);
		head.resize(n, -1);
		index.resize(n);

		mgr.init();
		build(0, -1);
		st.build(index, mgr.weight);
	}

	void build(int u, int p) {
		if (head[crChain] == -1) head[crChain] = u;
		chain[u] = crChain;
		index[u] = crIndex++;
		// heavy vertice
		int mx = -1, mxVal = -1;
		for (Node &i: adj[u]) if (i.v != p) {
			if (mgr.cnt[i.v] > mxVal) mx = i.v, mxVal = mgr.cnt[i.v];
		}
		if (mx != -1) build(mx, u);
		// light vertices
		for (Node &i: adj[u]) if (i.v != p && i.v != mx) {
			crChain++;
			build(i.v, u);
		}
	}

	int linearQuery(int a, int c) {
		int mn = I;
		while (true) {
			if (chain[a] == chain[c]) {
				return min(mn, st.query(index[c]+1, index[a]+1));
			}
			int hd = head[chain[a]];
			mn = min(mn, st.query(index[hd], index[a] + 1));
			a = mgr.parent[hd];
		}
		return I;
	}

	int query(int a, int b) {
		int c = lca.query(a, b);
		return min(
			linearQuery(a, c),
			linearQuery(b, c)
		);
	}
} hld;

/**
 * @kruskal
 * */
struct DSU {
	int p[N];

	void init() {
		for (int i = 0; i < n; i++) p[i] = i;
	}

	int find(int u) {
		if (p[u] == u) return u;
		return p[u] = find(p[u]);
	}

	bool join(int u, int v) {
		int a = find(u), b = find(v);
		if (a == b) return false;
		p[a] = b;
		return true;
	}
} dsu;

void kruskal(vector<Edge> &a) {
	sort(a.begin(), a.end(), [](Edge &i, Edge &j){
		return i.w > j.w;
	});
	dsu.init();
	for (Edge &e: a) {
		if (dsu.join(e.u, e.v)) {
			adj[e.u].push_back({e.v, e.w});
			adj[e.v].push_back({e.u, e.w});
		} else {
			upgrades.push_back(e);
		}
	}
}

/**
 * @drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// inp
	cin >> n >> m;
	vector<Edge> edges(m);
	for (Edge &e: edges) 
		e.get();
	// build
	kruskal(edges);
	lca.build();
	hld.build();
	// query
	ll res = 0;
	for (Edge &e: upgrades) {
		res += hld.query(e.u, e.v) - e.w;
	}
	cout << res << "\n";
	return 0;
}
