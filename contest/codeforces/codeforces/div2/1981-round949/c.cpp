
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Tue Jun  4 19:47:37 2024
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
#define cerr cerr << "[cerr] "

const int N = 2e5+7, I = 1e9+7, R = 1e9+7;
uint32_t n, a[N], ans[N];
vector<int> ind;
vector<int> dst;
vector<int> req;


int get_prefix()
{
    for (int i = 0; i < n; ++i)
        if (a[i] != -1)
            return i;
    return n;
}

int get_suffix()
{
    for (int i = n - 1; i >= 0; --i)
        if (a[i] != -1)
            return i;
    return n;
}

int min_transform_steps(int a, int b)
{
    if (a > b)
        swap(a, b);

    int x = 31 - __builtin_clz(a);
    int y = 31 - __builtin_clz(b);   // a <= b <=> x <= y
    if (a < b)
        a <<= y - x;
    else
        b <<= x - y;

    for (int i = max(x, y); i >= 0; --i) {
        int u = a >> i & 1;
        int v = b >> i & 1;
        if (u != v) {
            // `sim` highest bits are similar --> need to remove `rem` other bits
            int sim = max(y, x) - i;
            int rem = min(y, x) + 1 - sim;
            // (operations needed) == rem * 2 + d
            return rem * 2 + abs(y - x);
        }
    }

    return abs(y - x);   // zero bit difference after shifting
}

void prep()
{
    ind.clear();
    dst.clear();
    req.clear();

    int l = get_prefix(), r = l;
    for (; r < n; ++r) {
        if (a[r] == -1)
            continue;

        if (r - l > 1) {
            ind.push_back(l);                       // before sep by `-1`
            dst.push_back(r - l);                   // dis until next `> -1` val
            req.push_back(min_transform_steps(a[l], a[r]));
        }
        l = r;
    }

    // for (int i = 0; i < ind.size(); ++i)
        // cerr << ind[i] << " " << dst[i] << " " << req[i] << "\n";
}

bool calc_prefix()
{
    int l = 0, r = get_prefix();
    bool state = true;  // *2 first then /2
    int target = r == n ? 4 : a[r];

    for (--r; l <= r; --r) {
        if (state)
            target *= 2;
        else
            target /= 2;

        ans[r] = target;
        state = !state;
    }

    return r == n;
}

void calc_suffix()
{
    int l = get_suffix();
    bool state = true;
    int target = a[l];
    for (int i = l + 1; i < n; ++i) {
        if (state)
            target *= 2;
        else
            target /= 2;

        ans[i] = target;
        state = !state;
    }
}

vector<int> calc(uint32_t src, uint32_t des)
{
    int a = src, b = des;
    int x = 31 - __builtin_clz(a);
    int y = 31 - __builtin_clz(b);
    if (a < b)
        a <<= y - x;
    else
        b <<= x - y;
    int rem = x;

    for (int i = max(x, y); i >= 0; --i) {
        int u = a >> i & 1;
        int v = b >> i & 1;
        if (u != v) {
            // `sim` highest bits are similar --> need to remove `rem` other bits
            int sim = max(x, y) - i;
            rem = min(x, y) + 1 - sim;
            break;
        }
    }

    //
    vector<int> ans;
    while (rem--) {
        src >>= 1;
        ans.push_back(src);
    }

    int cur = __builtin_clz(src) - __builtin_clz(des);
    while (src < des) {
        src <<= 1;
        src |= (des >> (--cur)) & 1;
        ans.push_back(src);
    }
    if (ans.size())
        ans.pop_back(); // remove target

    return ans; // src == des at this point
}

void calc(uint32_t src, uint32_t des, int l, int r, int req)
{
    vector<int> ls = calc(src, des);

    int len = r - (l + 1);
    for (int i: ls)
         ans[++l] = i;

    bool state = true;
    uint32_t target = des;
    for (--r; l < r; --r) {
        if (state)
            target *= 2;
        else
            target /= 2;
        ans[r] = target;
        state = !state;
    }
}

void calc()
{
    // simple stuffs
    if (calc_prefix())
        return; // input full of `-1`
    calc_suffix();

    for (int i = 0; i < n; ++i) {
        if (a[i] != -1)
            ans[i] = a[i];
    }


    // fill in -1 boiz
    for(int i = 0; i < ind.size(); ++i) {
        calc(
            a[ind[i]],
            a[ind[i] + dst[i]],
            ind[i],
            ind[i] + dst[i],
            req[i]
        );
    }

}

bool check()
{
    // known vals
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == -1 || a[i + 1] == -1)
            continue;
        if ((a[i] >> 1) == a[i + 1] || a[i] == (a[i + 1] >> 1))
            continue;
        return false;
    }

    // unknown vals
    for (int i = 0; i < ind.size(); ++i) {
        int have = dst[i];
        int need = req[i];
        if (need > have || ((have - need) & 1)) {
            return false;
        }
    }

    return true;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    prep();
    if (check()) {
        calc();
        for (int i = 0; i < n; ++i)
            cout << ans[i] << " ";
        cout << "\n";
    }
    else
        cout << "-1\n";
}

int main()
{
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

