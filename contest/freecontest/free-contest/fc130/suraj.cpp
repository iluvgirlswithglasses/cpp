
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Dec 27 10:42:57 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define ll long long
ll lim, k;

bool check(ll m) {
	// kiểm tra xem 1 cửa sổ mở m tab thì thỏa hay ko
	// return (m*(m+1)>>1) * k <= lim;	// đk dấu = xảy ra: lim % k == 0
	return (m*(m+1)>>1) <= lim / k;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> lim >> k;
		ll l = 0, r = (ll) 1e9+7;
		while (l < r) {
			ll m = (l + r + 1) >> 1;
			if (check(m)) 
				l = m;
			else 
				r = m-1;
		}
		//
		ll res = l*k + (lim - k*(l*(l+1)>>1))/(l+1);
		cout << res << "\n";
	}
	return 0;
}
