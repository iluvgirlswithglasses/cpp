
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Thu Jun 13 21:41:34 2024
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

const int N = 2e5+7;
int64_t h, n;
int64_t a[N], c[N];

bool check(int64_t m)
{
    int64_t dmg = 0;
    for (int i = 0; i < n; ++i) {
        dmg += a[i] * (1 + m / c[i]);
        if (dmg >= h)
            return true;    // early break to prevent overflow
    }
    return false;
}

void solve()
{
    cin >> h >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    int64_t l = 0, r = 4e10 + 7;
    while (l < r) {
        int64_t m = (l + r) >> 1;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    cout << r + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

