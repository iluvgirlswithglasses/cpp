
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Sep 20 01:20:22 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
using namespace std;

#define ll long long
const ll R = 1e9+7;

ll sub(ll a, ll b) {
	a %= R, b %= R;
	ll c = a - b;
	if (c < 0) c += R;
	return c;
}

ll mul(ll a, ll b) {
	a %= R, b %= R;
	return (a*b) % R;
}

ll sigma(ll u, ll v) {
	ll n = v - u + 1; 
	if (n < 1) 
		return 0;
	ll x = (u<<1) + n - 1;
	if (n&1) return mul(x>>1, n);
	return mul(x, n>>1);
}

vector<ll> div(ll x) {
	vector<ll> f;
	for (ll i = 1; i*i <= x; i++) {
		f.push_back(i);
		if (i != x/i) f.push_back(x/i);
	}
	return f;
}

/**
 * c % i = c - (c//i)*i
 * --> values of c//i varies from c//b --> c//a
 * */

ll a, b, c, res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b >> c;
	res = mul(c, sub(b+1, a));
	/*
	basically my previous submission - https://oj.vnoi.info/src/517034

	but instead of fixing `i`
	now i'm fixing `floor(c/i)`
	*/
	for (ll x: div(c)) {
		res = sub(
			res, 
			mul(x, sigma( max(c/(x+1) + 1, a), min(c/x, b) ))
		);
	}
	cout << res << "\n";
	return 0;
}