
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Dec 13 18:23:08 2021
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
int q;
ll  n, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> q;
	while (q--) {
		cin >> n >> k;
		if (k < 3) {
			cout << "no\n";
		} else {
			cout << "yes\n";
		}
	}
	return 0;
}
