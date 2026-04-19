
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Sat Apr 18 23:05:59 2026
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

const int64_t N = 1e6+7, I = 1e17+7, R = 1e9+7;
int64_t n, k, a[N];

int64_t calc(int64_t anchor)
{
    int64_t cost = 0;

    for (int i = 0; i < n; ++i) {
        int64_t expected = anchor + i * k;
        cost += abs(a[i] - expected);
    }

    return cost;
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int64_t ans = I;
    for (int i = 1; i < 5001; ++i)
        ans = min(ans, calc(i));
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
