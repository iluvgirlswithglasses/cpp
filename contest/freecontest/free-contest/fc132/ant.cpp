
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 13 11:33:37 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 2e5+7;
int n, q, l, r, c, m, x[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> x[i];
	//
	while (q--) {
		cin >> l >> r;
		c = r - l + 1;
		if (c&1) {
			cout << 1 << "\n";
		} else {
			m = (l + r) >> 1;
			cout << x[m+1] - x[m] + 1 << "\n";
		}
	}
	return 0;
}

