
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Aug 15 18:37:40 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
1 <= a, b, c <= 2e5

{ a % k = ra, b % k = rb, c % k = rc }
{ (ra + rb) % k = 0, (rb + rc) % k = 0, (ra + rc) % k = 0 }
--> ra == rb == rc

*/

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long

ll n, k;

// ra == rb == rc == 0
ll f() {
	ll q = n / k;	// there are `q` numbers in [1:n] that mod k == 0
	return q*q*q;
}

// ra == rb == rc == k/2
ll g() {
	ll h = k>>1, q;
	if (n%k >= h)
		q = n / k + 1;
	else
		q = n / k;
	return q*q*q;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	if (k&1)
		cout << f() << "\n";
	else
		cout << f() + g() << "\n";
	return 0;
}
