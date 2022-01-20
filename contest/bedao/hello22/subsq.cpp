
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Jan 20 07:08:33 2022
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

/**
 * @ vars
 * */
int t;
ll x;

/**
 * @ perf
 * */
ll mpow(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	ll c = mpow(a, b>>1);
	if (b&1) return c*c*a;
	return c*c;
}

void calc(ll x) {
	// chuyển sang 2^x + 2^y + ... + 2^z
	const int h = 64 - __builtin_clzll(x);
	vector<ll> comp;
	for (int i = 0; i < h; i++) if (x>>i&1) {
		comp.push_back(i);
	}
	//
	cout << comp.size() << "\n";
	for (int i = 0; i < comp.size(); i++) {
		cout << mpow(2, comp[i] - i) << " ";
	}
	cout << "\n";
}

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> x;
		calc(x);
	}
	return 0;
}
