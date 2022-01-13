#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define file(s) freopen(s".inp", "r", stdin), freopen(s".out", "w", stdout)
#define PI acos(-1.0)
#define len(s) (int)s.size()
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
//---------------------------
const int N = 2e5 + 7;
const int M = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int n, m;
int a[N];

struct node{
    int val;
    bool orz;
};

struct segtree{
    node st[4 * N];
    int left(int p){return p << 1;}
    int right(int p){return (p << 1) + 1;}
    int mid(int l, int r){return (l + r) >> 1;}
    void build(int p, int l, int r){
        //cerr << p << " " << l << " " << r << "\n";
        if (l == r){
            st[p].val = a[l];
            st[p].orz = false;
            return;
        }
        if (l > r) return;
        build(left(p), l, mid(l, r));
        build(right(p), mid(l, r) + 1, r);
        if (st[left(p)].orz == false && st[right(p)].orz == false){
            st[p].val = st[left(p)].val | st[right(p)].val;
            st[p].orz = true;
        }else{
            st[p].val = st[left(p)].val ^ st[right(p)].val;
            st[p].orz = false;
        }
    }
    void update(int p, int l, int r, int idx, int val){
        if (l == idx && r == idx){
            st[p].val = val;
            return;
        }
        if (idx < l || r < idx){
            return;
        }

        update(left(p), l, mid(l, r), idx, val);
        update(right(p), mid(l, r) + 1, r, idx, val);
        if (st[left(p)].orz == false && st[right(p)].orz == false){
            st[p].val = st[left(p)].val | st[right(p)].val;
            st[p].orz = true;
        }else{
            st[p].val = st[left(p)].val ^ st[right(p)].val;
            st[p].orz = false;
        }
    }
    int get(){
        return st[1].val;
    }
} stree;

int main(){
    fio;
    file("bit");
    ///--------------
    scanf("%d %d", &n, &m);
    n = 1 << n;
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i + 1]);
    }
    stree.build(1, 1, n);
    for (int i = 0; i < m; i++){
        int idx, val;
        scanf("%d %d", &idx, &val);
        stree.update(1, 1, n, idx, val);
        printf("%d\n", stree.get());
    }
}
