
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 16 17:21:48 2022
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin >> n;
	int res = 0;
	for (ll i = 1; i <= n; i++) {
		res++;
		if (n - i <= i) break;
		n -= i;
	}
	cout << res << "\n";
	return 0;
}
