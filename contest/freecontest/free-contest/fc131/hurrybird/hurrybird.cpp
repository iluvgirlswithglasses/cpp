
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Oct 26 10:06:03 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
using namespace std;

#define ll long long
const ll I = 1e18+7;

ll n, m, a, b, x, y;

ll get_zigzac() {
	if (a < 2) return I;
	if ((b-a)&1) {
		return y*(b-a-1) + x;
	} else {
		return y*(b-a);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m >> x >> y;
		a = min(n, m), b = max(n, m);
		//
		ll sqr = min(y*(a-1), (x*(a-1))<<1);
		ll straight = x*(b-a);
		ll zigzac = get_zigzac();
		cout << sqr + min(straight, zigzac) << "\n";
	}
	return 0;
}

