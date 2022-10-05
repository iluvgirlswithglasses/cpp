
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Oct 05 13:17:03 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define ll long long
#define pi pair<ll, ll>
#define st first
#define nd second

const ll R = 998244353;

pi fib(ll n) {
    if (n == 0)
        return {0ll, 1ll};

    pi p = fib(n >> 1);
    ll c = p.st * ( ((p.nd<<1) - p.st + R) % R ); c %= R;
    ll d = p.st * p.st % R + p.nd * p.nd % R; d %= R;
    if (n & 1)
        return {d, (c + d) % R};
    return {c, d};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin >> n;
	pi f = fib(n+1);
	cout << (f.st * f.nd) % R << "\n";
	return 0;
}
