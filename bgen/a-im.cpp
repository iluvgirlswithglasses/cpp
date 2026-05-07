
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

constexpr uint64_t SPAN = 1e13;

// Binary Trie for integers (32-bit), supports insert, remove, k-th largest query
struct Trie {
    struct Node {
        int cnt;           // count of integers ending at this node
        int indice;
        Node* child[2];
        int childcnt[2];   // count of integers in each subtree

        Node() : cnt(0), child{nullptr, nullptr}, childcnt{0, 0} {}
    };

    int n;       // total count of integers in trie
    Node* root;

    Trie() : n(0), root(new Node()) {}

    // insert integer x into trie, O(32)
    void add(int64_t x, int indice) {
        x ^= (1ll<<63);
        n++;
        Node* p = root;
        for (int i = 63; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!p->child[bit])
                p->child[bit] = new Node();
            p->childcnt[bit]++;
            p = p->child[bit];
        }
        p->cnt++;
        p->indice = indice;
    }

    // returns k-th largest integer (0-indexed), O(32)
    // k=0 returns the largest, k=n-1 returns the smallest
    pair<int64_t, int> kth(int k) {
        int64_t res = 0;
        Node* p = root;
        k = n - k - 1;
        for (int i = 63; i >= 0; i--) {
            int right_cnt = p->childcnt[1];  // count of larger numbers
            if (right_cnt > k) {
                res |= ((int64_t)(1) << i);
                p = p->child[1];
            } else {
                k -= right_cnt;
                p = p->child[0];
            }
        }
        res ^= (1ll<<63);
        return { res, p->indice };
    }

    int size() const { return n; }
};

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

Trie trie;
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

            if (rank > trie.size()) {
                solvable = false;
                break;
            }

            if (rank == trie.size()) {
                if (trie.size() == 0) {
                    int64_t start = 1e16;
                    trie.add(0, node.idx);
                } else {
                    int64_t pre_largest = trie.kth(trie.size() - 1).first;
                    trie.add(pre_largest + SPAN, node.idx);
                }
            }

            else if (rank == 0) {
                int64_t lo = trie.kth(0).first;
                trie.add(lo - SPAN, node.idx);
                auto tmp = trie.kth(0);
            }

            else {
                int64_t lo = trie.kth(rank - 1).first;
                int64_t hi = trie.kth(rank).first;
                trie.add(lo/2 + hi/2, node.idx);
            }
        }
    }

    if (solvable) {
        cout << "YES\n";

        position.resize(n);
        FOR(i, 0, n)
            position[trie.kth(i).second] = i + 1;
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

