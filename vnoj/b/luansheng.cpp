
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Nov 30 15:36:11 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <set>
#include <cmath>
using namespace std;

#define u64 unsigned long long

u64 s3n(u64 n) {
	u64 i = 1;
	for (; i*i*i <= n; i++);
	return i;
}

u64 s2n(u64 n) {
	return ceil(sqrt(n));
}

u64 search(u64 l, u64 r, u64 x) {
	while (l < r) {
		u64 m = (l + r + 1) >> 1;
		if (m * (m + 1) <= x) {
			l = m;
		} else {
			r = m-1;
		}
	}
	if (l * (l+1) == x) return l;
	return 0;
}

/**
 * perf
 * */
void calc(u64 n) {
	set<u64> res;
	u64 l = s3n(n), r = s2n(n);
	//
	for (u64 i = 1; i <= l; i++) {
		if (n % (i * (i + 1)) == 0) {
			res.insert(i);
		}
		if (n % i == 0) {
			u64 x = n / i;
			u64 j = search(l, r, x);
			if (j != 0) res.insert(j);
		}
	}
	//
	if (res.size() > 0) {
		for (u64 i: res) 
			cout << i << " ";
	} else {
		cout << -1;
	}
	cout << "\n";
}

/**
 * drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		u64 n; cin >> n;
		calc(n);
	}
	return 0;
}
