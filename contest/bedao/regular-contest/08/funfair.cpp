
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Aug 16 13:55:04 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second
#define mk make_pair

const int N = 1e6+7;
int n, x, y, a[N], le, ri;
ll p[N];
bool hasPositive;

bool check(ll m) {
	set<pi> mem;	// {p[i], i}
	for (int i = 1; i <= n; i++) {
		if (a[i] < x || y < a[i]) {
			mem.clear();
		} else {
			
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 0) hasPositive = true;
	}
	if (hasPositive) {
		//
		for (int i = 1; i <= n; i++)
			p[i] = a[i] + p[i-1];
		// [l:r)
		ll l = -1e9-7, r = 1e15+7;
		while (l < r) {
			ll m = (l + r + 1) >> 1;
			if (check(m))
				l = m;
			else
				r = m-1;
		}
		cout << l << "\n" << le << " " << ri << "\n";
	} else {
		// all negative
		ll mx = -1e9-7;
		int pos = 0;
		for (int i = 1; i <= n; i++)
			if (x <= a[i] && a[i] <= y && a[i] > mx) 
				mx = a[i], pos = i;
		cout << mx << "\n" << pos << " " << pos << "\n";
	}
	return 0;
}
