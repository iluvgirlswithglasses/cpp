
/**
 * this is the sample implementation from cp-algorithm
 * my favorite implementation is written in vnoj/paths-old.cpp
 * the one in algorithms/data-structure/hld/hld.cpp is also worth consideration
 * */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
int n, plog[N<<1];
vector<int> adj[N];

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;

    LCA() {
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(0);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(to, h + 1);
                euler.push_back(node);
            }
        }
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
 * drivers
 * */
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	plog[1] = 0;
	for (int i = 2; i <= (n<<1); i++)
		plog[i] = plog[i/2]+1;
	//
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	LCA lca = LCA();
	while (true) {
		int u, v; cin >> u >> v;
		cout << lca.query(u, v) << "\n";
	}
	return 0;
}
