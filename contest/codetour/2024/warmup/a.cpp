
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Sat Jun  1 19:44:12 2024
style:      C-Kernel with custom pointer rule
tab-width:  4 spaces

 /\_/\
( o.o )
 > ^ <

See more about the style at:
https://iluvgirlswithglasses.github.io/style/cpp
*/

#include <array>
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
vector<array<int, 3>> a;
vector<array<int, 3>> b;

array<int, 3> decode(string s)
{
    const auto val = [](char c) {
        if ('0' <= c && c <= '9')
            return c - '0';
        return 10 + c - 'A';
    };
    const auto num = [&](string s) {
        return 16 * val(s[0]) + val(s[1]);
    };

    return { num(s.substr(1, 3)), num(s.substr(3, 3)), num(s.substr(5, 3)) };
}

int check(int i)
{
    const auto dif = [](int x, int y) {
        if (y >= x)
            return y - x;
        return y + 256 - x;
    };

    array<int, 3> ans;
    for (int j = 0; j < 3; j++)
        ans[j] = dif(a[i][j], b[i][j]);
    return (ans[0] << 16) | (ans[1] << 8) | ans[2];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        a.push_back(decode(s));
    }
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        b.push_back(decode(s));
    }

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[check(i)]++;
    }

    int mx = 0;
    for (auto& p: cnt)
        mx = max(mx, p.nd);
    double ans = (double) mx * 100 / n;

    printf("%.2f%%", ans);

    return 0;
}

