
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Tue Jun  4 15:44:07 2024
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
uint32_t n, m, l, r;

void solve()
{
    cin >> n >> m;
    r = n + m;
    l = n > m ? n - m : 0;
    // ans = cum_or[l, r]

    uint32_t ans = n;
    for (int i = 0; i < 31; ++i) {
        uint32_t msk = 1 << i;
        uint32_t mod;

        if (msk >= l) {
            mod = msk;
        } else {
            if (l & msk) {
                mod = l;
            } else {
                mod = l | msk;
                for (int b = 1; b < msk; b <<= 1)
                    mod &= ~b;
            }
        }

        // there is this bit among [l, r]
        if (l <= mod && mod <= r) {
            ans |= msk;
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

