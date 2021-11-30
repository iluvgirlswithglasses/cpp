
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Nov 30 15:57:08 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

void calc(int n) {
	for (int i = 1; i * (i+1) <= n; i++) {
		if (n % (i * (i+1)) == 0) cout << i << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		calc(n);
	}
	return 0;
}
