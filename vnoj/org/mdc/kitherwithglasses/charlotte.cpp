
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 16 17:39:19 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// do you know: "inamegane" is iluvgirlswithglasses' weeb name?

#include <iostream>
using namespace std;

#define ll long long
ll h, w;

ll sigma(ll l, ll r) {
	ll n = r - l + 1;
	return n * ((l<<1) + (n-1)) >> 1;
}

ll calc() {
	ll res = 0;
	if (h < w)
		return sigma(1, h) + sigma(w-h+1, w);
	return sigma(h-w, h) + sigma(1, w);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> h >> w;
	if (h >= 2 && w >= 2) {
		h -= 1, w -= 2;
		cout << calc() << "\n";
	} else {
		cout << "0\n";
	}
	return 0;
}
