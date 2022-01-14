
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Jan 14 13:09:49 2022
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
const int OPEN = 0, CLOSE = 1;

struct event {
	int t, x;

	void set(int a, int b) {
		t = a;
		x = b;
	}

	bool operator < (const event& e) {
		if (x == e.x) return t < e.t;
		return x < e.x;
	}
} e[N<<1];

int n, res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		e[i<<1  ].set(OPEN, a);
		e[i<<1|1].set(CLOSE, b);
	}
	n <<=1 ;
	sort(e, e+n);
	//
	int cr = 0;
	for (int i = 0; i < n; i++) {
		if (e[i].t == OPEN) {
			res = max(res, ++cr);
		} else {
			cr--;
		}
	}
	cout << res << "\n";
	return 0;
}
