
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Jan 15 18:55:40 2022
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

void calc(int a, int b, int c) {
	int st = (ll) a * b / (b + c),
	    nd = (ll) a * c / (b + c);
	cout << min(st, nd) << " " << max(st, nd) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		calc(a, b, c);
	}
	return 0;
}
