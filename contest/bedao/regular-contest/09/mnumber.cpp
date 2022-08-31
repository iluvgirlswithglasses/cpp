
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Aug 31 17:57:19 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define ll long long
ll c, a, b;

bool calc() {
	// c == a^2 * b^2 --> c == (a+b)(a-b)
	// call x = (a-b) --> c/x == a+b
	for (ll x = 1; x * x < c; x++) if (c % x == 0) {
		/*
			x = a - b, c/x = a + b
			--> x + b = c/x - b
			--> 2b = c/x - x

			x = a - b, c/x = a + b
			--> a - x = c/x - a
			--> 2a = c/x + x
		*/
		a = c/x + x, b = c/x - x;
		if ((a&1) || (b&1)) continue;
		a >>= 1, b >>= 1;
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> c;
	if (calc())
		cout << "YES\n" << a << " " << b << "\n";
	else 
		cout << "NO\n";
	return 0;
}
