
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Aug 27 19:08:49 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

/*
(a, b) -> (a-b, b)
*/

int a, b;

int calc() {
	int res = 0;
	while (a % b != 0) {
		res++;
		a = a - b;
		if (b > a) swap(a, b);
	}
	return res + a/b - 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << calc() << "\n";
	}
	return 0;
}
