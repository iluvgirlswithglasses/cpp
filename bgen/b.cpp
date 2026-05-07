
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Thu May  7 09:27:36 2026
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
typedef pair<int, int> pi;
typedef pair<long, long> pl;
#define st first
#define nd second
#define all(c) c.begin(), c.end()
#define has(c, a) c.find(a) != c.end()
#define nohas(c, a) c.find(a) == c.end()
#define FOR(i, l, r) for (int i = l; i < r; ++i)
#define FORR(i, l, r) for (int i = l; i <= r; ++i)
#define REP(n) for (int __rep = 0; __rep < n; ++__rep)

const int N = 1e6+7;
const ll I = 1e9+7, R = 1e9+7;
int64_t n, dp[N], cum[N];

void solve()
{
    cin >> n;
    cout << cum[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (i % 2 == 0) {
            dp[i] = 2 * dp[i >> 1];
        } else {
            dp[i] = dp[i >> 1] - 3 * dp[(i >> 1) + 1];
        }
        dp[i] %= R;
    }
    cum[0] = 0;
    FOR(i, 1, N) {
        cum[i] = (cum[i-1] + dp[i] + R) % R;
    }

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

