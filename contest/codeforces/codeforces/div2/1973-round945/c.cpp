
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Sat May 25 16:36:04 2024
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

/*!
So I am able to made every a[1 + 2i] a number larger than n,
let's try it out
!*/

const int N = 1e5+7, I = 1e9+7, R = 1e9+7;
int n, p[N], q[N];

void solve_odd()
{
    // make all a[1 + 2i] a local max
    vector<int*> candi;
    for (int i = 1; i < n; i += 2) {
        candi.push_back(&p[i]);
    }
    sort(all(candi), [](auto a, auto b) { return *a < *b; });

    int cur = n;
    for (int* itr: candi) {
        int idx = itr - p;
        q[idx] = cur--;
    }

    candi.clear();
    for (int i = 0; i < n; i += 2) {
        candi.push_back(&p[i]);
    }
    sort(all(candi), [](auto a, auto b) { return *a < *b; });
    for (int* itr: candi) {
        int idx = itr - p;
        q[idx] = cur--;
    }
}


void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int mx_pos = max_element(p, p+n) - p;
    if (mx_pos & 1) {
        solve_odd();
    } else {
        // flip then solve
        for (int l = 0, r = n-1; l < r; l++, r--)
            swap(p[l], p[r]);

        solve_odd();
        for (int l = 0, r = n-1; l < r; l++, r--)
            swap(q[l], q[r]);
    }

    for (int i = 0; i < n; i++) {
        cout << q[i] << " ";
    }
    cout << "\n";
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

