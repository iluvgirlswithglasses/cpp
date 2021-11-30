
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Nov 17 20:00:58 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/**
 *
 * problem link:
 * https://oj.vnoi.info/problem/tht21_tphcm_ckc_paths
 *
 * normally I would delete these failures
 * but look at this work....
 * how could I...
 * ----------------------------------------------------------------------
 *
 * khá giống testing round 08 / electric
 * khác ở chỗ phải cải tiến lên 2e5 đỉnh thay vì e3
 * ở đây sẽ cải tiến bằng LCA
 *
 * Quãng đường ngắn nhất gồm cạnh (u, v)
 * ==   Trọng lượng cây khung nhỏ nhất của cả đồ thị 
 *    - Trọng lượng cạnh to nhất trong cây khung từ u đến v
 *    + Trọng lượng (u, v)
 *
 */

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * def
 */
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second
const int N = 2e5+7, M = 2e5+7;

struct edge {
	int u, v, w;

	void set(int _u, int _v, int _w) {
		u = _u, v = _v, w = _w;
	}
};

pi mkpair(int i, int j) { 
	pi p; 
	p.st = i; 
	p.nd = j;
	return p;
}

/**
 * vars
 */
int n, m;
edge ed[M];
vector<pi> adj[N];		// dsk của mst
ll mst_weight;			// weight của mst

/**
 * DSU & Kruskal
 */
struct DSU {
	int p[N];

	void init() {
		for (int i = 0; i < n; i++) p[i] = i;
	}

	int find(int i) {
		if (p[i] == i) return i;
		p[i] = find(p[i]);
		return p[i];
	}

	bool join(int u, int v) {
		int a = find(u), b = find(v);
		if (a == b) 
			return false;
		p[a] = b;
		return true;
	}
};

ll kruskal(int m, edge* src) {
	vector<edge> ed(src, src+m);
	sort(ed.begin(), ed.end(), [](edge& i, edge& j){
		return i.w < j.w;
	});
	DSU dsu;
	dsu.init();
	//
	ll res = 0;
	for (int i = 0; i < m; i++) {
		int u = ed[i].u, v = ed[i].v, w = ed[i].w;
		if (dsu.join(u, v)) {
			res += w;
			adj[u].push_back(mkpair(v, w));
			adj[v].push_back(mkpair(u, w));
		}
	}
	return res;
}

/**
 * segtree
 * helps LCA
 */
struct segtree {
	// need N*4 nodes
	int n, f[N<<2];	

	int get(int l, int r) {
		int res = 0;
		for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
			if (l&1) res = max(res, f[l++]);
			if (r&1) res = max(res, f[--r]);
		}
		return res;
	}

	void build(vector<int>& weight) {
		n = weight.size();
		for (int i = 0; i < n; i++) {
			f[i+n] = weight[i];
		}
		for (int i = n-1; i >= 1; i--) {
			f[i] = max(f[i<<1], f[i<<1|1]);
		}
	}
};

struct lca_segtree {
	vector<int> height, euler, first;
	vector<int> segtree;

	void build(vector<int> &h, vector<int> &e, vector<int> &f) {
		height = h;
		euler = e;
		first = f;
		segtree.resize(euler.size()<<2);
		build(1, 0, euler.size() - 1);
	}

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int query(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

/**
 * LCA
 */
struct LCA {
	//
	vector<pi>* adj;
	
	// weight[i]: store the weight of the path from euler[i-1] -> euler[i]
	vector<int> euler, weight, height, first;
	// present[i] store the locations of node `i` in euler path
	vector<set<int>> present;

	lca_segtree st_lca;
	segtree st_w;

	void build(int n, vector<pi>* _adj) {
		adj = _adj;
		euler.reserve(n<<1);
		weight.reserve(n<<1);
		height.resize(n);
		first.resize(n);
		present.resize(n);
		//
		dfs(0, -1, 0, 0);
		st_lca.build(height, euler, first);
		st_w.build(weight);
	}

	void dfs(int u, int p, int w, int h) {
		first[u] = euler.size();
		present[u].insert(euler.size());
		euler.push_back(u);
		weight.push_back(w);
		height[u] = h;
		//
		for (pi &v: adj[u]) if (v.st != p) {
			dfs(v.st, u, v.nd, h+1);
			present[u].insert(euler.size());
			euler.push_back(u);
			weight.push_back(v.nd);
		}
	}

	int lca(int u, int v) {
		return st_lca.query(u, v);
	}

	// tìm đường đi ngắn nhất từ u -> lca(u, v)
	//                           v -> lca(u, v)
	// --> cạnh có trọng số lớn nhất từ u -> v 
	//     là cạnh có trọng số lớn nhất trong 2 đường đi đó
	int get(int u, int v) {
		int p = lca(u, v),
			a = *--present[p].upper_bound(first[u]),
			b = *--present[p].upper_bound(first[v]);
		return max(
			st_w.get(a+1, first[u]+1),
			st_w.get(b+1, first[v]+1)
		);
	}
};

/**
 * drivers
 */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		ed[i].set(--u, --v, w);
	}
	//
	mst_weight = kruskal(m, ed);
	LCA lca;
	lca.build(n, adj);
	//
	for (int i = 0; i < m; i++) {
		int u = ed[i].u, v = ed[i].v, w = ed[i].w;
		ll res = mst_weight - lca.get(u, v) + w;
		//
		cout << res << "\n";
	}
	return 0;
}

