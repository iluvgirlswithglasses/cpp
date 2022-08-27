
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Aug 27 19:57:41 2022
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
const int N = 1e6+7;
int n;

struct event {
	int t, x;	// 0: close, 1: open

	bool operator < (const event &e) const {
		if (x == e.x) return t < e.t;
		return x < e.x;
	}
} e[N<<1];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> e[i<<1].x >> e[i<<1|1].x;
		e[i<<1  ].t = 1;	// open
		e[i<<1|1].t = 0;	// close
	}
	sort(e, e+(n<<1));
	//
	ll res = 0, cr = 0;
	for (int i = 0; i < (n<<1); i++) {
		if (e[i].t == 1) 
			res += cr++;
		else 
			cr--;
	}
	cout << res << "\n";
	return 0;
}
