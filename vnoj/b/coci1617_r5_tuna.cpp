
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 14 10:28:49 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// I did this cuz the name made me curious
// well... you can tell it didn't meet my expectation

#include <iostream>
using namespace std;

int n, x, s, i, j, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> x;
	while (n--) {
		cin >> i >> j;
		if (abs(i - j) > x) {
			cin >> k;
			s += k;
		} else {
			s += max(i, j);
		}
	}
	cout << s << "\n";
	return 0;
}

