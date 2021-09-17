
// https://cp-algorithms.com/algebra/fibonacci-numbers.html

#include <iostream>
using namespace std;

typedef long long ll;
#define st first
#define nd second

const ll R = 111539786ll;

pair<ll, ll> fib(int n) {
    if (n == 0)
        return {0ll, 1ll};

    auto p = fib(n >> 1);
    ll c = (p.st * ( ((p.second<<1) - p.st + R) % R )) % R;
    ll d = ((p.st * p.st) % R + (p.second * p.second) % R) % R;
    if (n & 1)
        return {d, (c + d) % R};
    return {c, d};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    //
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << fib(n).nd << "\n";
    }
    return 0;
}
