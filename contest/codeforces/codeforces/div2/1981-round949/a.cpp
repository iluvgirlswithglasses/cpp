
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Tue Jun  4 15:34:09 2024
style:      C-Kernel with custom pointer rule
tab-width:  4 spaces

 /\_/\
( o.o )
 > ^ <

See more about the style at:
https://iluvgirlswithglasses.github.io/style/cpp
*/

// basically find the 2^n number

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

const int N = 1e9+7, I = 1e9+7, R = 1e9+7;
int l, r;
set<uint32_t> s;

void solve()
{
    cin >> l >> r;
    uint32_t x = *--s.upper_bound(r);
    cout << 31 - __builtin_clz(x) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 32; ++i)
        s.insert(1ull<<i);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

