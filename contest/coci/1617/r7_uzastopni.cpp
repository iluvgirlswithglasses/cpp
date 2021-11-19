
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Nov 19 01:07:43 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
with X == targeted number

	n*(2u + n-1) = 2X
<=> (2X/n) - n + 1 = 2u
--> find n that makes u a natural number
*/

#include <iostream>
using namespace std;

#define ll long long
ll x, xd;

ll u(int n) {
	if (xd % n != 0) return -1;
	ll vt = xd/n - n + 1;
	if (vt&1) return -1;
	if (vt<2) return -1;
	return vt>>1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> x; xd = x<<1;
	for (ll n = 2; n*(n-1) <= xd; n++) {
		ll r = u(n);
		if (r != -1) {
			cout << r << " " << r+n-1 << "\n";
		}
	}
	return 0;
}

