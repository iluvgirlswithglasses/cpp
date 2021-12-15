
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Dec 15 21:09:21 2021
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

const int N = 1e5+7;

struct event {
	// t == 0 --> open
	// t == 1 --> close
	int x, i, t;

	void set(int _x, int _i, int _t) {
		x = _x, i = _i, t = _t;
	}

	bool operator < (const event& e) {
		if (x == e.x) 
			// close typ is put in higher priority
			return t > e.t;
		return x < e.x;
	}
} a[N<<1];

int n, m, fin, dp[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, l;
		cin >> x >> l;
		a[i<<1  ].set(x-l, i, 0);
		a[i<<1|1].set(x+l, i, 1);
	}
	m = n << 1;
	sort(a, a+m);
	//
	for (int _i = 0; _i < m; _i++) {
		int x = a[_i].x, i = a[_i].i, t = a[_i].t;
		if (t == 0) {
			// open
			dp[i] = fin + 1;
		} else {
			// close
			fin = max(fin, dp[i]);
		}
	}
	cout << *max_element(dp, dp+n) << "\n";
	return 0;
}
