
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Wed Apr 29 21:25:12 2026
style:      C-Kernel with custom pointer rule
tab-width:  4 spaces

 /\_/\
( o.o )
 > ^ <

See more about the style at:
https://iluvgirlswithglasses.github.io/style/cpp
*/

#include <utility>
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

typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()
#define has(c, a) c.find(a) != c.end()

// ---- inp ------------------------------------------------------------------------------
const int N = 1e5+7, I = 1e9+7, R = 1e9+7;
int n, a[N];
vector<int> adj[N];

struct prio {
    int i, w, d;
};


// ---- euler tour -----------------------------------------------------------------------
int cur_idx = 0;
int beg_idx[N];
int end_idx[N];
int depth[N];

void build_euler_tour(int u, int p, int d)
{
    depth[u] = d;
    beg_idx[u] = cur_idx++;
    for (int v: adj[u]) {
        if (v != p)
            build_euler_tour(v, u, d + 1);
    }
    end_idx[u] = cur_idx++;
}


// ---- segtree --------------------------------------------------------------------------
int tour_n, f[N<<2];

void upd(int l, int r)
{
    for (l += tour_n, r += tour_n; l < r; l >>= 1, r >>= 1) {
        if (l&1) f[l++] += 1;
        if (r&1) f[--r] += 1;
    }
}

int query(int i)
{
    int ans = 0;
    for (i += tour_n; i > 0; i >>= 1)
        ans += f[i];
    return ans;
}


// ---- driver ---------------------------------------------------------------------------
void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    build_euler_tour(0, -1, 0);
    tour_n = cur_idx;

    vector<prio> nodes;
    for (int i = 0; i < n; ++i)
        nodes.push_back({ i, a[i], depth[i] });
    sort(all(nodes), [](auto& x, auto& y) {
        if (x.w == y.w)
            return x.d > y.d;
        return x.w > y.w;
    });

    vector<int> ans(n, 0);
    for (auto [u, w, d]: nodes) {
        int l = beg_idx[u];
        int r = end_idx[u];
        ans[u] = query(l);
        upd(l, r + 1);

        // clog << "queried " << l << " got " << ans[u] << " | updated " << l << " " << r << "\n";
    }

    for (int x: ans)
        cout << x << " ";
    cout << "\n";

    // for (int i = 0; i < n; ++i)
    //     clog << beg_idx[i] << " ";
    // clog << "\n";
    // for (int i = 0; i < n; ++i)
    //     clog << end_idx[i] << " ";
    // clog << "\n";
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

