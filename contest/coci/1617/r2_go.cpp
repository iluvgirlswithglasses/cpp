
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Nov 19 00:13:23 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
using namespace std;

int n, r, k, m, res;
string p, s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	while (n--) {
		cin >> p >> k >> m;
		int cnt = 0;
		//
		while (m >= k) {
			cnt++;
			m -= k;
			m += 2;
		}
		//
		if (cnt > r) {
			s = p;
			r = cnt;
		}
		res += cnt;
	}
	cout << res << "\n" << s << "\n";
	return 0;
}
