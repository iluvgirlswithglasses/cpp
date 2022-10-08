
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct  8 10:24:37 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// for greater `N` limit, use euler totient

#include <iostream>
using namespace std;


int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int n, cnt;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	// the trap `n == 1` was suggested by me btw
	for (int i = 1; i < n; i++)
		cnt += gcd(n, i) == 1;
	cout << cnt << "\n";
	return 0;
}
