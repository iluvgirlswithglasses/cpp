
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 05 14:08:04 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

typedef unsigned int u32;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	float f;
	cin >> f;
	//
	u32 g = * (u32 *) &f;
	for (int i = 31; i >= 0; i--)
		cout << (g>>i&1);
	cout << "\n";
	return 0;
}
