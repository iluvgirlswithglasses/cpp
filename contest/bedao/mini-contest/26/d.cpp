
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Mon Apr 20 09:42:48 2026
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


struct Edge
{
    int u, v, w;
};

struct DSU {
    int p[N];

    void init(int n)
    {
        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    int find(int i)
    {
        if (p[i] == i)
            return i;
        p[i] = find(p[i]);
        return p[i];
    }

    bool join(int u, int v)
    {
        int a = find(u), b = find(v);
        if (a == b)
            return false;
        p[a] = b;
        return true;
    }
} dsu;


int n, m;
int64_t A, B;
Edge edges[N];
int degree[N];


void solve()
{
    cin >> n >> A >> B;
    m = n - 1;
    dsu.init(n);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = { u, v, w };
    }
    sort(edges, edges + m, [](auto& a, auto& b) { return a.w < b.w; });

    int64_t ans = B * n;
    int64_t components = n;
    int64_t sum_weight = 0;

    for (int i = 0; i < m; ++i) {
        auto& edge = edges[i];
        if (degree[edge.u] >= 2 || degree[edge.v] >= 2)
            continue;

        sum_weight += edge.w;
        --components;
        ++degree[edge.u];
        ++degree[edge.v];
        ans = min(ans, A * sum_weight + B * components);
    }
    cout << ans << "\n";
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

