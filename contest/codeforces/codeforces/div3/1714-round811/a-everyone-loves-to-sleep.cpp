
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Sep 11 20:06:53 2022
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

const int D = 1440, N = 12;
int n, x;	// x: time of sleep
int v[N];	// v: alarm list

int calc(int h, int m) {
	return h*60 + m;
}

void prf(int y) {
	if (y >= D) y -= D;
	cout << (y/60) << " " << (y%60) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, h, m; 
		cin >> n >> h >> m;
		x = calc(h, m);
		for (int i = 0; i < n; i++) {
			cin >> h >> m;
			v[i] = calc(h, m);
			if (v[i] < x) v[i] += D;
		}
		//
		int y = *min_element(v, v+n);
		prf(y - x);
	}
	return 0;
}
