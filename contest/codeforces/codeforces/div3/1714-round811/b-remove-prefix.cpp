
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Sep 11 20:22:29 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 2e5+7;
int  n, a[N];
bool c[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) 
			cin >> a[i];
		for (int i = 0; i <= n; i++)
			c[i] = false;
		//
		int res;
		for (int i = n-1; i >= 0; i--) {
			if (c[a[i]]) break;
			c[a[i]] = true;
			res = i;
		}
		cout << res << "\n";
	}
	return 0;
}
