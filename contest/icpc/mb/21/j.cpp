
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct 08 15:47:27 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long

const int N = 104;
int n;
ll  k, a[N], b[N];

// m: days of work
bool check(ll m) {
	ll total = 0;
	for (int i = 0; i < n; i++) {
		ll off = m / (b[i] + 1), on = m - off;
		total += a[i] * on;
		if (total >= k) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	ll l = 1, r = 1 + (k / *max_element(a, a+n));
	while (l < r) {
		ll m = (l + r) >> 1;
		if (check(m))
			r = m;
		else
			l = m+1;
	}
	cout << r << "\n";
	return 0;
}
