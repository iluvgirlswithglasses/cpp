
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Dec 18 22:47:13 2021
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
#define st first
#define nd second

const int K = 2e5+7;
int w, h;
int len, pos[K], mul[4];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll res = 0;
		//
		cin >> w >> h;
		mul[0] = mul[1] = h;
		mul[2] = mul[3] = w;
		//
		for (int i = 0; i < 4; i++) {
			cin >> len;
			for (int j = 0; j < len; j++) {
				cin >> pos[j];
			}
			ll x = pos[len-1] - pos[0];
			res = max(res, x * mul[i]);
		}
		cout << res << "\n";
	}
	return 0;
}
