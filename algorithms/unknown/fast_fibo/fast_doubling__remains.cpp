
// https://cp-algorithms.com/algebra/fibonacci-numbers.html

#include <iostream>
using namespace std;

#define st first
#define nd second
#define ll long long

const int R = 1e9+7;

pair<ll, ll> fib(ll n) {
    if (n == 0)
        return {0, 1};

    pair<ll, ll> p = fib(n >> 1);
    ll c = p.st * ( ((p.nd<<1) - p.st + R) % R ); c %= R;
    ll d = p.st * p.st % R + p.nd * p.nd % R; d %= R;
    if (n & 1)
        return {d, (c + d) % R};
    return {c, d};
}

int main() {
    int n; cin >> n;
    cout << fib(--n).nd << endl;
    return 0;
}
