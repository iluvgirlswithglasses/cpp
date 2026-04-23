
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Thu Apr 23 21:40:23 2026
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

typedef pair<int, int64_t> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()
#define has(c, a) c.find(a) != c.end()

const int N = 2e5+7;
const int64_t I = 1e18+7;


struct Candidate
{
    int node;
    int64_t appendable;
    int64_t unappendable;
};


int n;
int64_t A, B;
int64_t dp[N][3];
vector<pi> adj[N];


void dfs(int u, int parent)
{
    vector<Candidate> candidates;
    dp[u][0] = 0;
    dp[u][1] = -I;
    dp[u][2] = -I;

    for (auto& [v, saving]: adj[u]) {
        if (v == parent)
            continue;
        dfs(v, u);
        int64_t no_add = *max_element(dp[v], dp[v] + 3);
        int64_t add = max(dp[v][0], dp[v][1]);

        dp[u][2] = max({
            dp[u][2] + no_add,          // skip this edge
            dp[u][1] + saving + add     // take this edge
        });
        dp[u][1] = max({
            dp[u][1] + no_add,          // skip this edge
            dp[u][0] + saving + add     // take
        });
        dp[u][0] = dp[u][0] + no_add;
    }
}


void solve()
{
    cin >> n >> A >> B;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        int64_t saving = max(B - A * w, static_cast<int64_t>(0));
        adj[u].push_back(make_pair(v, saving));
        adj[v].push_back(make_pair(u, saving));
    }

    int64_t max_cost = B * n;
    dfs(1, 0);
    cout << max_cost - *max_element(dp[1], dp[1] + 3) << "\n";
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

