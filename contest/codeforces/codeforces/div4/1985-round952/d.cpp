
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Thu Jun 13 18:47:53 2024
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
int h, w;

void solve()
{
    cin >> h >> w;
    int64_t x = 0, y = 0, n = 0;

    for (int r = 1; r <= h; ++r) {
        for (int c = 1; c <= w; ++c) {
            char v; cin >> v;
            if (v == '.')
                continue;
            x += r;
            y += c;
            ++n;
        }
    }

    cout << x / n << " " << y / n << "\n";
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

