
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Aug 24 17:37:03 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

int n, h, w, d, x;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> w >> h;
	d = h*h + w*w;
	while (n--) {
		cin >> x;
		if (x*x <= d) {
			cout << "DA\n";
		} else {
			cout << "NE\n";
		}
	}
	return 0;
}
