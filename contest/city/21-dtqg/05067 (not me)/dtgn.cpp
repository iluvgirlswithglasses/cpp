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
const int N = 2e3 + 7;
const int M = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
pii event[N];
int n, evc = 0;

int main(){
    fio;
    file("dtgn");
    ///--------------
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d %d", &event[evc].FS, &event[evc + 1].FS);
        event[evc].SC = 0;
        event[evc + 1].SC = 1;
        evc += 2;
    }
    sort(event, event + evc);
    int ctr = 0, ans = 0;
    for (int i = 0; i < evc; i++){
        if (event[i].SC == 0){
            ctr++;
        }else{
            ctr--;
        }
        ans = max(ans, ctr);
    }
    printf("%d", ans);
}
