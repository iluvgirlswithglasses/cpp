
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Thu Jun 13 18:18:54 2024
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
int n;

int sum(int x)
{
    int ans = 0;
    for (int i = x; i <= n; i += x)
        ans += i;
    return ans;
}

void solve()
{
    int x = 0, best = 0;

    cin >> n;
    for (int i = 2; i <= n; ++i)
        if (sum(i) > best)
            x = i, best = sum(i);
    cout << x << "\n";
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

