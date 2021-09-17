#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = (int)3e5 + 3;
const int maxa = (1 << 20) + 3;
 
 
int n;
int a[maxn];
int cnt[2][maxa];
 
 
int main() {
    std::ios_base::sync_with_stdio(false);
 
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cnt[1][0] = 1;
    int x = 0;
    long long res = 0;
    for(int i = 0; i < n; ++i) {
        x ^= a[i];
        res += cnt[i % 2][x];
        ++cnt[i % 2][x];
 
    }
    cout << res << endl;
    return 0;
}

