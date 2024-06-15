
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Sat Jun 15 20:01:07 2024
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
int n, q, x[N];
vector<pi> t;
vector<int64_t> p;

void solve()
{
    cin >> n >> q;
    t.resize(n);
    for (pi& i: t)
        cin >> i.nd >> i.st;
    for (int i = 0; i < q; ++i)
        cin >> x[i];
    sort(all(t), [](pi& a, pi& b) { return a.st < b.st; });

    p.resize(n);
    p[0] = t[0].nd;
    for (int i = 1; i < n; ++i)
        p[i] = p[i-1] + t[i].nd;

    for (int i = 0; i < q; ++i) {

        pi dummy = { x[i], I };
        auto itr = upper_bound(all(t), dummy);
        if (itr == t.begin())
            cout << "0\n";
        else
            cout << p[itr - t.begin() - 1] << "\n";

    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}

