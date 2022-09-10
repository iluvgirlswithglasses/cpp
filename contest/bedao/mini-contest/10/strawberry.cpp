
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Sep 10 17:53:05 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long

ll n, x, a, res;

ll sigma(ll u, ll n, ll d) {
	return (n * ((u<<1) + (n-1)*d)) >> 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> x;
	while (n--) {
		cin >> a;
		res += sigma(a, (x-1)/a, a);
	}
	cout << res << "\n";
	return 0;
}
