
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Dec  9 18:50:07 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
something I just have learnt this year:

căn bậc q của n = n^(1/q) = e^(ln(n)/q) = p
*/

#include <iostream>
#include <cmath>
using namespace std;

/*
n <= 1e18 --> q < 63
*/

#define u64 unsigned long long

bool is_prime(u64 p) {
	for (u64 i = 2; i * i <= p; i++)
		if (p % i == 0) return false;
	return true;
}

u64 mpow(u64 p, int q) {
	if (q == 0) return 1;
	if (q == 1) return p;
	u64 c = pow(p, q>>1);
	if (q&1) return p * c * c;
	return c * c;
}

void check(u64 n) {
	for (int q = 2; q < 63; q++) {
		u64 p = round(exp(log(n) / q));
		if (is_prime(p) && mpow(p, q) == n) {
			cout << p << " " << q << "\n";
			return;
		}
	}
	cout << 0 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	u64 n; cin >> n;
	check(n);
	return 0;
}
