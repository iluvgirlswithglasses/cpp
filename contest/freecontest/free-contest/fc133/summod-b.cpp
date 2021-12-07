
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Dec  7 23:32:07 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define u64 unsigned long long
const u64 R = 1e9+7;
u64 a, b, c, l, r, res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b >> c;
	for (u64 i = a; i <= b; i++) {
		res += c % i;
		res %= R;
	}
	cout << res << "\n";
	return 0;
}
