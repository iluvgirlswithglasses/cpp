
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Thu May  7 09:27:34 2026
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

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<long, long> pl;
#define st first
#define nd second
#define all(c) c.begin(), c.end()
#define has(c, a) c.find(a) != c.end()
#define nohas(c, a) c.find(a) == c.end()
#define FOR(i, l, r) for (int i = l; i < r; ++i)
#define FORR(i, l, r) for (int i = l; i <= r; ++i)
#define REP(n) for (int __rep = 0; __rep < n; ++__rep)

struct Node
{
    int rel;
    int fin;
    int idx;
};

const int N = 2e5+7;
const ll I = 1e9+7, R = 1e9+7;
int n;
Node nodes[N];

vector<int> indices;
vector<int> position;

void solve()
{
    cin >> n;
    FOR(i, 0, n) {
        cin >> nodes[i].rel >> nodes[i].fin;
        nodes[i].idx = i;
    }
    sort(nodes, nodes+n, [](auto& a, auto& b) { return a.fin < b.fin; });

    bool solvable = true;
    FOR(i, 0, n) {
        if (nodes[i].fin != i + 1) {
            solvable = false;
            break;
        }
    }

    if (solvable) {
        for (int sz = 0; sz < n; ++sz) {
            auto node = nodes[sz];
            int rank = nodes[sz].rel - 1;
            if (rank > indices.size()) {
                solvable = false;
                break;
            }
            indices.insert(indices.begin() + rank, node.idx);
        }
    }

    if (solvable) {
        cout << "YES\n";

        position.resize(n);
        FOR(i, 0, n)
            position[indices[i]] = i + 1;
        FOR(i, 0, n)
            cout << position[i] << " ";
        cout << "\n";
    } else {
        cout << "NO\n";
    }

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

