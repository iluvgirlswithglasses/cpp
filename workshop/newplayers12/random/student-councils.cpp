
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Nov  4 18:48:45 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <vector>
using namespace std;

#define ll long long

const ll K = 22, N = 52;
const ll I = 5e10+7;
ll k, n, a[N];

bool valid(ll m, ll k) {
	vector<ll> v(a, a+n);
	for (ll &i: v) if (i > m) i = m;
	int i = 0;
	while (k--) {
		ll cr = 0;
		while (i < n && cr < m) {
			if (v[i] > m - cr) {
				ll add = m - cr;
				v[i] -= add;
				cr = m;
			} else {
				cr += v[i];
				v[i] = 0;
				i++;
			}
		}
		if (cr < m) return false;
	}
	return true;
}

int main() {		
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> k >> n;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	//
	ll l = 0, r = I;
	while (l < r) {
		ll m = (l + r + 1) >> 1;
		if (valid(m, k)) {
			l = m;
		} else {
			r = m-1;
		}
	}
	cout << l << "\n";
	return 0;
}

