
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Sep 18 22:52:26 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define ll long long
const ll LIM = 1e7;
ll n;
vector<ll> res;

ll strip(ll n) {
	for (ll i = 2; n > 1 && i <= LIM; i++) while (n % i == 0) {
		n /= i;
	}
	return n;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (ll i = 2, j = i*i; j <= n && i <= LIM; i++, j = i*i)
		if (n % j == 0) res.push_back(j);
	int r = res.size();
	//
	for (ll i = 0; i < r; i++)
	for (ll j = i; j < r; j++) {
		ll x = res[i]*res[j];
		if (x > LIM && n % x == 0) res.push_back(x);
	}
	//
	ll y = strip(n);
	if (y > 1) {
		ll x = sqrt(y);
		if (x * x == y) {
			res.push_back(y);
			for (int l = 0; l < r; l++) {
				if (n % (res[l]*y) == 0) res.push_back(res[l]*y);
			}
		}
	}
	//
	if (res.size() == 0)
		cout << -1;
	else {
		set<ll> ans(res.begin(), res.end());
		for (ll i: ans) cout << i << " ";
	}
	cout << "\n";
	return 0;
}
