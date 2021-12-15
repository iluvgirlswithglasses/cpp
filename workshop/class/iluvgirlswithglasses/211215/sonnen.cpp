
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Dec 15 18:03:31 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define st first
#define nd second
#define ll long long

pair<ll, ll> fib(ll n) {
    if (n == 0)
        return {0, 1};

    pair<ll, ll> p = fib(n >> 1);
    ll c = p.st * ((p.nd<<1) - p.st);
    ll d = p.st * p.st + p.nd * p.nd;
    if (n & 1)
        return {d, c + d};
    return {c, d};
}

int main() {
    // freopen("SONNEN.INP", "r", stdin);
    // freopen("SONNEN.OUT", "w", stdout);
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    if (n == 0)
        cout << "0\n";
    else
        cout << fib(--n).nd << endl;
    return 0;
}
