
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Sat May 25 17:19:13 2024
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

const int64_t N = 2e5+7, I = 1e12+7, R = 1e9+7;
int64_t n, k;
int64_t a[N];

bool check(int64_t m)
{
    int64_t remain = k;
    for (int i = 0; i < n && a[i] < m; i++) {
        remain -= m - a[i];
        if (remain < 0)
            return false;
    }
    return true;
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    if (n == 1) {
        cout << a[0] + k << "\n";
        return;
    }

    /*!
    1 number in `i` can cover range [i-n/2 : i+n/2]
    --> buy such that it maximize the minimum
    !*/
    int64_t l = 0, r = *max_element(a, a+n) + k;
    while (l < r) {
        int64_t m = (l + r + 1) >> 1;
        if (check(m)) {
            // can make all a[i] >= m
            l = m;
        } else {
            // otherwise
            r = m - 1;
        }
    }
    // maximum perms obtained
    int64_t lim = k;
    for (int i = 0; i < n; i++)
        lim += a[i];
    lim -= n - 1;


    // let x = min{ a[i] }
    // x will be distance to each other exactly `n` distance
    // let n = 3 --> perm coverange = count(x) * n
    // ? y x ? y x ? ? ? ? ? ?
    // - - - - - _                  (subarray can start at - or _)
    int64_t candidate = l * n;

    // you can't start at _ if there are multiple x for x = min{ a[i] }
    // e.g. if there's 2 min value, then ans = candidate - (2 - 1)
    // otherwise, if there's 1 min value, then ans = candidate - (1 - 1)
    int64_t remain = k;
    int64_t min_cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= l) {
            min_cnt++;
            remain -= l - a[i];
        }
    }
    min_cnt -= remain;
    //
    cout << min(lim, candidate - min_cnt + 1) << "\n";
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

