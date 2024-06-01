
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Sat Jun  1 19:44:20 2024
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
#define int int64_t
#define clog clog << "[clog] "

const int N = 1e6+7, I = 1e9+7, R = 1e9+7;
int h, w, x;
double d, r;

double calc(int h, int w)
{
    int minc = ceil(w / d);
    int minr;
    if (h <= x) {
        minr = 1;
    } else {
        minr = ceil(
            (double)(2.0 * h + x) / (double)(3 * x)
        ) + 0.001;
    }

    double short_edge = (minc * d) - r;

    if (w <= short_edge) {
        // tiles row 1 == tiles row 2
        return minr * minc;
    } else {
        // tiles row 1 == 1 + tiles row 2
        int shortrow = (minr + 1) / 2;
        int longrow = (minr) / 2;
        return shortrow * minc + longrow * (minc + 1);
    }
}

void solve()
{
    cin >> h >> w >> x;
    r = sqrt(3) / 2 * x;
    d = 2 * r;

    if (h <= r && w <= r) {
        cout << "1\n";
        return;
    }

    cout << min(calc(h, w), calc(w, h)) << "\n";
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

