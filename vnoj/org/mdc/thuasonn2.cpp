
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep 30 00:25:03 2022
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
ll n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	cout << (1ll<<(63 - __builtin_clzll(n))) << "\n";
	return 0;
}
