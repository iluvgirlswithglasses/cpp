#include <bits/stdc++.h>
using namespace std;

#define name ""
#define ini freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
#define long long long
#define db double
#define pii pair <int, int>
#define pll pair <long, long>
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

template <class T> inline void chmin(T &a, const T& val) { if (a > val) a = val; }
template <class T> inline void chmax(T &a, const T& val) { if (a < val) a = val; }
template <class T> long sqr(T a) { return 1ll * a * a; }
template <class T, class U> istream& operator >> (istream &f, pair <T, U> &x){
  f >> x.first >> x.second; return f;
}
template <class T, class U> ostream& operator << (ostream &g, pair <T, U> &x){
  g << x.first << ' ' << x.second; return g;
}
template <class T> istream& operator >> (istream &f, vector <T> &a){
  for (auto &x : a) f >> x; return f;
}
template <class T> ostream& operator << (ostream &g, vector <T> &a){
  for (auto x : a) g << x << ' '; return g;
}
template <class T> void compress(T &a){
  sort(all(a)); a.resize(unique(all(a)) - a.begin());
}

const db pi = acos(-1.00);
const db eps = 1e-6;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

const int N = 1e5 + 1;
long f[1 << 16][17][17];
int n, m, a[N], cnt[1 << 16], K;

long dp(int mask, int i, int k){
  if (i == m && k == 0){
    return cnt[mask];
  } else if (i == m){
    return 0;
  }
  if (k < 0) return 0;
  if (f[mask][i][k] != -1) return f[mask][i][k];
  long tot = 0;
  tot += dp(mask, i + 1, k); tot += dp(mask ^ (1 << i), i + 1, k - 1);
  return f[mask][i][k] = tot;
}

int main()
{
  fastio;
  cin >> n >> m >> K;
  for (int i = 1; i <= n; i++){
    string s; cin >> s;
    int cur = 0;
    for (char c : s){
      cur = cur * 2 + (c - '0');  
    }
    cnt[cur]++; a[i] = cur;
  }
  long ans = 0;
  for (int mask = 0; mask < (1 << m); mask++){
    for (int i = 0; i <= m; i++){
      for (int k = 0; k <= m; k++){
        f[mask][i][k] = -1;
      }  
    }
  }
  for (int i = 1; i <= n; i++){
    ans += dp(a[i], 0, K);  
  }
  cout << ans / 2;
  return 0;
}