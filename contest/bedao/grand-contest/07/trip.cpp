
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 21 14:05:04 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#include <cstdio>	// debug

/**
 * defs
 * */
#define ll long long
const int N = 1e5+7;

/**
 * vars
 * */
int n, a[N], last[N];

/**
 * utils
 * */
void compress() {
	set<int> s(a, a+n);
	vector<int> v(s.begin(), s.end());
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	}
}

/**
 * segtree
 * */
int f[N<<1];

void upd(int p, int v) {
	for (p = p - 1 + n; p > 0; p >>= 1) {
		f[p] += v;
	}
}

int get(int l, int r) {
	int res = 0;
	for (l = l - 1 + n, r = r - 1 + n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res += f[l++];
		if (r&1) res += f[--r];
	}
	return res;
}

/**
 * drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	compress();
	//
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		int l = last[ a[i] ];
		last[ a[i] ] = i;
		upd(l, -1);
		res += get(l+1, i);
		upd(i, +1);
	}
	//
	cout << res << "\n";
	return 0;
}

