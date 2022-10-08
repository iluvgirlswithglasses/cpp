
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct  8 10:23:30 2022
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
	cout << (1ll<<(63 - __builtin_clzll(n))) << "\n";
	return 0;
}
