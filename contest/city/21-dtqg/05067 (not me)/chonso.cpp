#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define file(s) freopen(s".inp", "r", stdin), freopen(s".out", "w", stdout)
#define PI acos(-1.0)
#define len(s) (int)s.size()
#define FS first
#define SC second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
//---------------------------
const int N = 1e6 + 7;
const int M = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int n;
int a[N];
int pf[N];
pair <int, pii> best[N];

int main(){
    fio;
    file("chonso");
    ///--------------
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }
    for (int i = 1; i <= n << 1; i++){
        pf[i] = pf[i - 1] + a[i];
    }
    int cr = n >> 1;
    for (int i = 1; i <= n; i++){
        best[i].FS = pf[i + cr - 1] - pf[i - 1];
        best[i].SC.FS = i;
        best[i].SC.SC = i + cr - 1;
    }
    sort(best + 1, best + n + 1);
    int pl = best[n].SC.FS, pr = best[n].SC.SC, top = n - 1;
    while((pl <= best[top].SC.FS && best[top].SC.FS <= pr)
          || (pl <= best[top].SC.SC && best[top].SC.SC <= pr)
          || (pl <= (best[top].SC.FS + n) % (n << 1) && (best[top].SC.FS + n) % (n << 1) <= pr)
          || (pl <= (best[top].SC.SC + n) % (n << 1) && (best[top].SC.SC + n) % (n << 1) <= pr)
          && top >= 1){
        pl = max(pl, best[top].SC.FS);
        pr = min(pr, best[top].SC.SC);
        top--;
    }
    printf("%d", pf[n] - best[top].FS);
}
