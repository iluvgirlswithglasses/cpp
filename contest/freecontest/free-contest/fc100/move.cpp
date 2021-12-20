
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Dec 19 20:27:59 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

int m, n, a, b, x, y;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n >> a >> b >> x >> y;
	int w = abs(a - x), h = abs(b - y);
	if ((w&1) || (h&1)) {
		cout << "-1\n";
	} else {
		h >>= 1;
		w >>= 1;
		cout << h + w << "\n";
	}
	return 0;
}
