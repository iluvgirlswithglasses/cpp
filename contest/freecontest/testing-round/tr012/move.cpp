
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 20 15:30:32 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

int n, m, a, b, c, d;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> a >> b >> c >> d;
	if ((a&1) == (c&1) && (b&1) == (d&1)) {
		int x = abs(a-c)>>1,
			y = abs(b-d)>>1;
		cout << x + y << "\n";
	} else {
		cout << "-1\n";
	}
	return 0;
}
