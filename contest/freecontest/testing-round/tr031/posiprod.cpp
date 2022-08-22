
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Jun 13 11:30:42 2022
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
int n, a, pc, nc, zero;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) zero++;
		else if (a < 0) nc++;
		else pc++;
	}
	//
	if (zero) {
		cout << -1 << "\n";
	} else {
		cout << min(nc, pc) << "\n";
	}
	return 0;
}
