
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Sat Jun  8 18:39:56 2024
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
int n, q, cnt;
vector<int> h;
vector<int> query;


int f[N<<1];

int get(int l, int r)
{
    int ans = 0;
    for (l += cnt, r += cnt; l < r; l >>= 1, r >>= 1) {
        if (l&1) ans += f[l++];
        if (r&1) ans += f[--r];
    }
    return ans;
}

void upd(int p, int v)
{
    for (p += cnt; p > 0; p >>= 1) {
        f[p]++;
    }
}

void compress()
{
    set<int> s(all(h));
    s.insert(all(query));
    cnt = s.size();

    vector<int> v(all(s));
    for (int& i: h)
        i = lower_bound(all(v), i) - v.begin();
    for (int& i: query)
        i = lower_bound(all(v), i) - v.begin();
}

int operate(int h)
{
    int ans = get(0, h + 1);
    upd(h, 1);
    return ans;
}

void solve()
{
    cin >> n >> q;
    h.resize(n);
    for (int& i: h)
        cin >> i;

    query.resize(q);
    for (int& i: query)
        cin >> i;

    compress();
    for (int i: h)
        operate(i);
    for (int i: query)
        cout << 1 + operate(i) << "\n";

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

