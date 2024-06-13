
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Thu Jun 13 21:27:49 2024
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

const int N = 1e6+7, I = 1e9+7, R = 1e9+7;
int64_t x, y, z, k;

void solve()
{
    cin >> x >> y >> z >> k;
    int64_t ans = 0;

    for (int64_t a = 1; a <= x; ++a) {
        for (int64_t b = 1; b <= y; ++b) {

            int64_t c = k / (a * b);
            if (a * b * c != k || c > z)
                continue;

            ans = max(
                ans,
                (x - a + 1) * (y - b + 1) * (z - c + 1)
            );

        }
    }

    cout << ans << "\n";
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

