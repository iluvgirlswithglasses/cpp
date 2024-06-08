
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Sat Jun  8 20:56:25 2024
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
vector<int64_t> a;
vector<int64_t> p;
vector<int64_t> s;


bool solve()
{
    cin >> n;
    a.resize(n + 1);

    // prefix
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // solve ---------------------------------------------------------
    int l = 1;
    int64_t cur = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] <= cur) {
            cur += a[i];
        } else {
            cur = 1;
            l = i + 1;
        }
    }
    if (l == n + 1)
        return false;


    for (int i = l - 1; i >= 1; --i) {
        if (a[i] <= cur) {
            cur += a[i];
        } else {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        if (solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

