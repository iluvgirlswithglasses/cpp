
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Aug 27 19:31:20 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

int l, r;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> r;
	l = 1;
	while (l < r)
		cout << l++ << " " << r-- << " ";
	if (l == r)
		cout << l << "\n";
	else
		cout << "\n";
	return 0;
}
