
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Sat Jun  8 21:42:22 2024
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

typedef pair<int64_t, int64_t> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()
#define has(c, a) c.find(a) != c.end()
#define int int64_t

const int N = 5007, I = 1e9+7, R = 1e9+7;
int n, k, d;
int t[N], a[N], b[N];
int cnt[N], one[N], two[N], dif[N];
vector<pi> candi;   // candi[i]: <diff t, type t> where t is the i-th best type for cutting off
map<int, vector<int>> adj;

int f[N<<1];

int query(int l, int r)
{
    int ans = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) ans += f[l++];
        if (r&1) ans += f[--r];
    }
    return ans;
}

void update(int p, int v)
{
    for (p += n; p >= 1; p >>= 1)
        f[p] += v;
}


void read()
{
    cin >> n >> k >> d;

    adj.clear();
    memset(cnt, 0, sizeof(int) * n);
    memset(f, 0, sizeof(int) * n * 2);

    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        t[i]--;
        cnt[t[i]]++;
        adj[t[i]].push_back(i);
    }

    for (int i = 0; i < k; ++i)
        cin >> a[i];
    for (int i = 0; i < k; ++i)
        cin >> b[i];

    for (int i = 0; i < n; ++i) {
        int u = t[i];
        one[u] = a[u] * min((int) 1, cnt[u]) + b[u] * max(cnt[u] - 1, static_cast<int>(0));
        two[u] = a[u] * min((int) 2, cnt[u]) + b[u] * max(cnt[u] - 2, static_cast<int>(0));
        dif[u] = one[u] - two[u];
    }

    candi.clear();
    for (auto& p: adj) {
        candi.push_back({ dif[p.st], p.st });
    }
    sort(all(candi));

}

bool can_solo(int diff, int type)
{
    return true;
}

void solve()
{
    read();

    int ans = 0;

    if (d == n) {
        for (auto& [type, pos]: adj) {
            ans += min(one[type], two[type]);
        }
    } else {
        int x = adj.size();
        vector<int> v;
        for (auto& [type, pos]: adj)
            v.push_back(type);

        for (int msk = 0; msk < (1<<x); ++msk) {
            int cur = 0;
            for (int i = 0; i < x; ++i) {
                if (msk >> i & 1)
                    cur += one[v[i]];
                else
                    cur += two[v[i]];
            }

            ans = min(ans, cur);
        }
    }


    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

