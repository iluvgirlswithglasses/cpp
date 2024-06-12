
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Sat Jun 15 20:22:06 2024
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

const vector<pair<char, char>> win = {
    {'R', 'S'},
    {'P', 'R'},
    {'S', 'P'},
};

const int N = 1e6+7, I = 1e9+7, R = 1e9+7;
int n;
map<char, int> a, b;

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char x; cin >> x;
        a[x]++;
    }
    for (int i = 0; i < n; ++i) {
        char x; cin >> x;
        b[x]++;
    }

    int ans = 0;

    // win rounds
    for (auto [w, l]: win) {
        int dif = min(a[w], b[l]);
        a[w] -= dif;
        b[l] -= dif;
        ans += dif;
    }

    // draw rounds
    for (auto [w, l]: win) {
        int dif = min(a[w], b[w]);
        a[w] -= dif;
        b[w] -= dif;
    }

    // lose rounds
    for (auto [t, cnt]: b) {
        ans -= cnt;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
    return 0;
}

