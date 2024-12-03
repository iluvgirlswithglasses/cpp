
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Wed Nov  6 15:40:31 2024
style:      C-Kernel with custom pointer rule
tab-width:  4 spaces

 /\_/\
( o.o )
 > ^ <

See more about the style at:
https://iluvgirlswithglasses.github.io/style/cpp
*/

#include <iostream>
#include <vector>
using namespace std;

constexpr int I = 1007;
int x, y, m, ass[I], vst[I];
vector<int> adj[I]; // 1-indexed

bool dfs(const int root, int u)
{
    vst[u] = root;

    for (int v: adj[u]) {
        if (ass[v] == 0 || (vst[ass[v]] != root && dfs(root, ass[v]))) {
            ass[v] = u;
            return true;
        }
    }

    return false;
}

int solve()
{
    int answ = 0;
    int root = 0;
    for (int i = 1; i <= x; ++i)
        answ += dfs(++root, i);
    return answ;
}

int main(int argc, const char* argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> x >> y >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    cout << solve() << "\n";
    return 0;
}

