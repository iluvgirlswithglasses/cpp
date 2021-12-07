
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Dec  7 21:29:37 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

/**
 * c % i = c - (c//i)*i 	(oh shit that was how I calculate mod in python a year ago)
 * --> values of c//i varies from c//b --> c//a
 * */

#define u64 unsigned long long
const u64 R = 1e9+7;
u64 a, b, c, l, r, res;

u64 mul(u64 a, u64 b) {
	a %= R, b %= R;
	return (a * b) % R;
}

u64 dec(u64 a, u64 b) {
	a %= R, b %= R;
	return (a - b + R) % R;
}

u64 sigmashit(u64 u, u64 n) {
	u64 comp = (u<<1) + n-1;
	if (n&1) return mul(n, comp>>1);
	return mul(n>>1, comp);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b >> c;
	l = c / b, r = c / a;
	res = mul(c, b-a+1);
	//
	for (u64 i = l; i <= r; i++) {
		/*
		sum of numbers `j` which make c // j == i

		notes:
		3 // x == 1 --> x in {2..3}
		7 // x == 1 --> x in {4..7}
		14 // x == 2 --> x in {5..7}
		*/
		u64 il = max(c / (i + 1) + 1, a),
		    ir = min(c / i, b),
		    n  = ir - il + 1,
		    s  = sigmashit(il, n);
		// from this, all i do is bignum handling
		res = dec(res, mul(s, i));
	}
	cout << res << "\n";
	return 0;
}
