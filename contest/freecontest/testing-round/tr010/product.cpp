
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Dec 14 20:29:32 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b;
	cin >> a >> b;
	a *= b;
	if (a == 0) {
		cout << "0\n";
	} else if (a > 0) {
		cout << "1\n";
	} else if (a < 0) {
		cout << "-1\n";
	}
	return 0;
}
