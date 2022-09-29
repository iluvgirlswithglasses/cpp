
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Sep 29 15:06:14 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

int h, m, a, b;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> h >> m >> a >> b;
	h = h - a + b;
	if (h < 0) h += 24;
	if (h >= 24) h -= 24;
	cout << h << " " << m << "\n";
	return 0;
}
