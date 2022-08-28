
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Aug 28 20:01:18 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cmath>
using namespace std;

#define ll long long
const ll I = 3e8+7;
ll c, a, b;

bool is_sqr(ll x) {
	ll y = sqrt(x);
	return y*y == x;
}

bool calc() {
	for (ll j = 1; j <= I; j++) {
		ll x = c + j*j;
		if (is_sqr(x)) {
			a = sqrt(x);
			b = j;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> c;
	if (calc()) {
		cout << "YES\n" << a << " " << b << "\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
