
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Tue May  5 10:30:10 2026
style:      C-Kernel with custom pointer rule
tab-width:  4 spaces

 /\_/\
( o.o )
 > ^ <

See more about the style at:
https://iluvgirlswithglasses.github.io/style/cpp
*/

#pragma GCC optimize ("O3")

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
#define st first
#define nd second
#define all(c) c.begin(), c.end()
#define has(c, a) c.find(a) != c.end()

const int N = 2e5+7;
const ll I = 1e9+7, R = 1e9+7;
int n, q;
ll w[N];

// Heavy-Light Decomposition: point-update + path-sum-query (1-indexed)
template <int MAXN>
struct HLD
{
    int n;
    vector<int> adj[MAXN];
    int parent[MAXN], depth[MAXN], subtree[MAXN];
    int chain[MAXN], head[MAXN], pos[MAXN];
    int num_chains, cur_pos;

    int64_t t[MAXN * 2];  // segment tree for point-update + range-sum

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // call after adding all edges
    void build(int root = 1)
    {
        num_chains = cur_pos = 0;
        fill(head, head + MAXN, 0);
        fill(t, t + MAXN * 2, 0);
        dfs_size(root, 0, -1);
        dfs_hld(root, -1);
    }

    // set value at node u, O(log n)
    void update(int u, int64_t val)
    {
        int p = pos[u] + n;
        t[p] = val;
        for (p >>= 1; p > 0; p >>= 1)
            t[p] = t[p<<1] + t[p<<1|1];
    }

    // add delta to node u, O(log n)
    void add(int u, int64_t delta)
    {
        for (int p = pos[u] + n; p > 0; p >>= 1)
            t[p] += delta;
    }

    // sum of values on path u->v, O(log^2 n)
    int64_t path_query(int u, int v)
    {
        int64_t res = 0;
        while (chain[u] != chain[v]) {
            if (depth[head[chain[u]]] < depth[head[chain[v]]]) swap(u, v);
            res += seg_query(pos[head[chain[u]]], pos[u] + 1);
            u = parent[head[chain[u]]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        res += seg_query(pos[u], pos[v] + 1);
        return res;
    }

    // LCA of u and v, O(log n)
    int lca(int u, int v)
    {
        while (chain[u] != chain[v]) {
            if (depth[head[chain[u]]] < depth[head[chain[v]]]) swap(u, v);
            u = parent[head[chain[u]]];
        }
        return depth[u] < depth[v] ? u : v;
    }

private:
    void dfs_size(int u, int d, int p)
    {
        parent[u] = p;
        depth[u] = d;
        subtree[u] = 1;
        for (int v : adj[u])
            if (v != p) {
                dfs_size(v, d + 1, u);
                subtree[u] += subtree[v];
            }
    }

    void dfs_hld(int u, int p)
    {
        if (head[num_chains] == 0) head[num_chains] = u;
        chain[u] = num_chains;
        pos[u] = cur_pos++;

        int heavy = -1;
        for (int v : adj[u])
            if (v != p && (heavy == -1 || subtree[v] > subtree[heavy]))
                heavy = v;
        if (heavy != -1) dfs_hld(heavy, u);

        for (int v : adj[u])
            if (v != p && v != heavy) {
                num_chains++;
                dfs_hld(v, u);
            }
    }

    int64_t seg_query(int l, int r)
    {
        int64_t res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
        }
        return res;
    }
};
HLD<N> hld;

void solve()
{
    cin >> n >> q;
    hld.n = n;

    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        hld.add_edge(u, v);
    }
    hld.build(1);
    for (int i = 1; i <= n; ++i)
        hld.update(i, w[i]);

    int t, s, x;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> s >> x;
            hld.update(s, x);
        } else {
            cin >> s;
            cout << hld.path_query(s, 1) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    // int tt; cin >> tt;
    int tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}

