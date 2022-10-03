
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Oct  3 18:06:11 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define u64 unsigned long long
const u64 R = 2027;
u64 n, nr;

u64 mod(u64 i) {
	return i % R;
}

u64 pow(u64 x, u64 y) {
	if (y == 0ull) return 1ull;
	if (y == 1ull) return x;
	u64 c = pow(x, y>>1);
	if (y&1)
		return mod(mod(c*c)*x);
	return mod(c*c);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n; 
	n = mod(n);
	u64 s = mod( n * (1 + mod(n*n)) );
	u64 r = s * pow(2, R-2);	// see my euler candy pb for explanation
	//
	cout << mod(r) << "\n";
	return 0;
}
