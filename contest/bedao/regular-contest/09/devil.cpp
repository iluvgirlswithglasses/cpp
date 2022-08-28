
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Aug 28 20:32:43 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
hoặc là chia cho các hàng có `m` con
hoặc là chia cho hàng `2i` có `m` con, hàng `2i+1` có `m+1` con
*/

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
const ll I = 1e12+7, S2I = 1e6+7;
ll n;

ll case_1() {
	ll d = n - 1;
	// mỗi hàng m con
	for (ll m = 2; m * m <= n; m++) if (n % m == 0) {
		d = min(d, abs(m - (n/m)));
	}
	return d;
}

ll case_2() {
	ll res = n - 1;
	// lệch 1 con
	for (ll m = 2; m < n && m * m <= I; m++) {
		ll x = m/2, y = (m+1)/2;
		// giả sử các hàng x nhiều hơn các hàng y 1 con cóc
		ll d1 = I;
		if ((n-x) % m == 0) {
			ll yc = (n-x) / m;	// thì mỗi hàng y sẽ có yc con cóc
			d1 = abs(m - (yc+1));
		}
		// nếu y nhiều hơn x 1 con cóc
		ll d2 = I;
		if ((n-y) % m == 0) {
			ll xc = (n-y) / m;	// thì mỗi hàng x sẽ có xc con cóc
			d2 = abs(m - (xc+1));
		}
		//
		res = min(res, min(d1, d2));
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	cout << min(case_1(), case_2()) << "\n";
	return 0;
}
