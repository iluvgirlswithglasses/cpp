
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Sat Apr 18 23:57:39 2026
style:      C-Kernel with custom pointer rule
tab-width:  4 spaces

 /\_/\
( o.o )
 > ^ <

See more about the style at:
https://iluvgirlswithglasses.github.io/style/cpp
*/

// can't believe I only realized this approach
// after almost finishing a whole ass sweep line implementationg

#include <utility>
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

const int N = 5e5+7, I = 1e9+7, R = 1e9+7;
int n;
// vector<int> adj[N];
bool influenced[N];

struct Person {
    int loc;
    int rad;
    int idx;
} person[N];


void build_adj(bool pass1)
{
    int infl = person[0].rad;
    int infl_owner = person[0].idx;
    int last_x = person[0].loc;

    for (int i = 1; i < n; ++i) {
        auto cur = person[i];
        int x = cur.loc, y = cur.rad;

        int remaning_infl = infl - abs(x - last_x);
        if (remaning_infl >= y) {

            // i fucking hate impl problems
            if (x == last_x && y == infl) {

                if (pass1) {
                    influenced[cur.idx] = true;
                    infl = remaning_infl;
                    last_x = x;
                } else {

                }

            } else {
                influenced[cur.idx] = true;
                infl = remaning_infl;
                last_x = x;
            }

        } else {
            infl = y;
            infl_owner = cur.idx;
            last_x = x;
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int loc, rad;
        cin >> loc >> rad;
        person[i] = { loc, rad, i };
    }

    // forw pass
    sort(person, person + n, [](auto& a, auto& b) { return a.loc < b.loc; });
    build_adj(true);

    // back pass
    for (int l = 0, r = n - 1; l < r; ++l, --r)
        swap(person[l], person[r]);
    for (int i = 0; i < n; ++i)
        person[i].loc = -person[i].loc;
    build_adj(false);

    // count
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (!influenced[i])
            ++ans;
    cout << ans << "\n";

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

