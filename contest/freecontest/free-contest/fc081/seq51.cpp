
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Dec  3 16:35:55 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

int n, a;
int res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int l = 0, r = 0; r < n; r++) {
		cin >> a;
		int len = r - l + 1;
		if (a < len) {
			int gap = len-a;
			l += gap;
		}
		res = max(res, r - l + 1);
	}
	//
	cout << res << "\n";
	return 0;
}
