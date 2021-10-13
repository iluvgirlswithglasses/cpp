
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 10 16:40:47 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5+7;
ll s;
int n, a[N];

// (s / n == k) &&
// ((s - x) / (n - 2) == k)
// --> x = 2s/n
ll calc() {
	if ((s<<1) % n != 0) 
		return 0;
	ll x = (s<<1)/n;
	//
	ll res = 0;
	map<int, ll> m;
	m[a[0]] = 1;
	for (int i = 1; i < n; i++) {
		int pre = x - a[i];
		res += m[pre];
		m[a[i]]++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		s = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
		}
		cout << calc() << "\n";
	}
	return 0;
}

