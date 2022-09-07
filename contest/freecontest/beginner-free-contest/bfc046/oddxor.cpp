
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Sep  7 12:52:13 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// codeforces/1567-round742-div2/b/mex-xor.cpp

#include <iostream>
using namespace std;

/*
1    3    5    7    9    11   13   15
0001 0011 0101 0111 1001 1011 1101 1111

--> 1^3^5^7 == 0
*/

#define ll long long
ll l, r;

ll calc() {
	// ensure `l` and `r` are odd numbers
	l |= 1;
	if (!(r&1)) r--;
	if (r < l) return 0;
	//
	ll res = 0;
	if (r - l <= 16) {
		// bé quá thì trâu thôi
		for (ll i = l; i <= r; i+=2)
			res ^= i;
	} else {
		// còn lớn thì chặt khúc giữa
		ll lo = ((l-1+7)/8)*8 + 1, hi = (r/8)*8+1;
		for (ll i = l; i < lo; i+=2)
			res ^= i;
		for (ll i = hi; i <= r; i+=2)
			res ^= i;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> l >> r;
	cout << calc() << "\n";
	return 0;
}
