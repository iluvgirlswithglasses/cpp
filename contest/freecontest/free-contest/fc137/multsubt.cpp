
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Jun 16 19:45:06 2022
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
ll x, k;
bool s[100005];
int c;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> x >> k;
	//
	while (x > 1) {
		if (x % k == 0) {
			x /= k;
			s[c++] = 0;
		} else {
			x++;
			s[c++] = 1;
		}
	}
	//
	cout << c << "\n";
	for (int i = 0; i < c; i++) 
		cout << 1 + s[i] << " ";
	cout << "\n";
	return 0;
}
