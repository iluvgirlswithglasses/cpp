
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Sep  1 14:24:56 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

// I literally came across this problem and solved it in a dream
// IN A FUCKING DREAM
// So ig imma write the solution down

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	int c = gcd(a, b);
	return c * (a/c) * (b/c);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b; cin >> a >> b;
	if (a < b) swap(a, b);
	cout << lcm(a, b) << "\n";
	return 0;
}
