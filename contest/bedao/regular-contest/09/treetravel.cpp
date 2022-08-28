
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Aug 28 21:59:12 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e5+7, R = 1e9+7;
int n, root;
vector<int> adj[N];
int parent[N];
// childCnt[i]: the largest line of vertices that `i` can be the root of
int childCnt[N];

// calculate childCnt
int dfs(int u) {
	if (adj[u].size() == 0) return 1;
	int mx = 0;
	for (int v: adj[u]) {
		mx = max(mx, dfs(v));
	}
	childCnt[u] = mx;
	return mx + 1;
}

// need this to complete the given problem
struct LCA {

	struct SegTree {
		int n;
		pi f[N<<2];	// f[i]: {depth, index}

		void build(vector<int>& euler, vector<int>& depth) {
			n = euler.size();
			for (int i = 0; i < n; i++)
				f[i+n] = make_pair(depth[euler[i]], euler[i]);
			for (int i = n-1; i > 0; i--)
				f[i] = min(f[i<<1], f[i<<1|1]);
		}

		int get(int l, int r) {
			pi res = make_pair(2e9, -1);
			for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
				if (l&1) res = min(res, f[l++]);
				if (r&1) res = min(res, f[--r]);
			}
			return res.nd;
		}
	} segtree;

	vector<int> euler, first, depth;

	void init(int u) {
		euler.reserve(n<<1);
		first.resize(n+1);
		depth.resize(n+1);
		dfs(u, 0);
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

	// SegTree updates and queries the values in the flatten tree (index[N])
	struct SegTree {
		int f[N<<1];

		void init() {
			for (int i = 0; i < n; i++)
				f[i+n] = 1;
		}

		void upd(int l, int r, int v) {
			for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
				if (l&1) {
					f[l] += v;
					if (f[l] >= R) f[l] -= R;
					l++;
				}
				if (r&1) {
					--r;
					f[r] += v;
					if (f[r] >= R) f[r] -= R;
				}
			}
		}

		int get(int i) {
			int res = 0;
			for (i += n; i > 0; i >>= 1) {
				res += f[i];
				if (res >= R) res -= R;
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

	int query(int u) {
		return segtree.get(index[u]);
	}

} hld;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p; cin >> p;
		if (p == 0)
			root = i;
		parent[i] = p;
		adj[p].push_back(i);
	}
	//
	dfs(root);
	lca.init(root);
	hld.segtree.init();
	hld.init(root);
	//
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		if (u != root)
			hld.linear_update(parent[u], root, hld.query(u));
	}
	//
	for (int i = 1; i <= n; i++) {
		cout << hld.query(i) << " ";
	}
	cout << "\n";
	return 0;
}
