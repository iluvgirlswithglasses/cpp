
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Thu Apr 30 17:18:47 2026
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

typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()
#define has(c, a) c.find(a) != c.end()

const int N = 2e5+7, I = 1e9+7, R = 1e9+7;
int n;
int64_t a[N];
vector<int> adj[N];


// euler tour
int tour_n = 0;
int beg_idx[N];
int end_idx[N];

void build_euler_tour(int u, int p)
{
    beg_idx[u] = tour_n++;
    for (int v: adj[u]) {
        if (v == p)
            continue;
        build_euler_tour(v, u);
    }
    end_idx[u] = tour_n++;
}

// segtree
int64_t f[N<<2];

void update(int i, int64_t v)
{
    f[i += tour_n] = v;
    for (i >>= 1; i > 0; i >>= 1)
        f[i] = f[i<<1] + f[i<<1|1];
}

int64_t query(int l, int r)
{
    int64_t ans = 0;
    for (l += tour_n, r += tour_n; l < r; l >>= 1, r >>= 1) {
        if (l&1) ans += f[l++];
        if (r&1) ans += f[--r];
    }
    return ans;
}

void build_segtree()
{
    for (int i = 0; i < n; ++i) {
        f[tour_n + beg_idx[i]] = a[i];
        f[tour_n + end_idx[i]] = a[i];
    }

    for (int i = tour_n - 1; i > 0; --i)
        f[i] = f[i<<1] + f[i<<1|1];
}


void solve()
{
    // inp
    int q, typ, s, x;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    // offine proc
    build_euler_tour(0, -1);
    build_segtree();

    // query
    while (q--) {
        cin >> typ;
        if (typ == 1) {
            cin >> s >> x;
            --s;
            update(beg_idx[s], x);
            update(end_idx[s], x);
        } else {
            cin >> s;
            --s;
            cout << query(beg_idx[s], end_idx[s] + 1) / 2 << "\n";
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

