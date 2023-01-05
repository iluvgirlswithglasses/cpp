
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Jan  5 23:16:55 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

typedef long long ll;

ll pow(ll a, ll b) {
	// calc a**b
	ll res = 1;
	while (b > 0) {
		if (b & 1) 
			res *= a;
		b >>= 1;
		a *= a;
	}
	return res;
}

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	while (true) {
		ll a, b; cin >> a >> b;
		cout << pow(a, b) << "\n";
	}
	return 0;
}
