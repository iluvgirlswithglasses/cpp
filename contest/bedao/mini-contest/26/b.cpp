
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Sat Apr 18 23:28:17 2026
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

const int N = 1e6+7, I = 1e9+7, R = 1e9+7, B = 21;
int n, a[N];
vector<int> last(B, -1);    // last[i] = last number with i-th bit equals 1
set<int> known;

// 1: 001   1
// 2: 010   2
// 4: 100   3
// 6: 110   0
// 1: 001   0

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i) {
        known.insert(a[i]);

        vector<int> add_order;
        for (int b = 0; b < B; ++b) {
            if ((a[i] >> b) & 1)
                continue;
            int l = last[b];
            add_order.push_back(l);
        }
        sort(all(add_order), [](int x, int y) { return x > y; });
        int cur = a[i];
        for (auto l: add_order) {
            cur |= a[l];
            known.insert(cur);
        }

        // record this
        for (int b = 0; b < B; ++b) {
            if ((a[i] >> b) & 1)
                last[b] = i;
        }
    }

    cout << known.size() << "\n";
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

