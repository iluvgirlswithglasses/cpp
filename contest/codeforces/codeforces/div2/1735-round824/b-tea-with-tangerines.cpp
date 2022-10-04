
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Oct 04 15:00:10 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &i: a) cin >> i;
		//
		sort(a.begin(), a.end());
		ll  res = 0;
		int lim = (a[0]<<1)-1;
		for (int i = 1; i < n; i++) {
			res += (a[i] + lim - 1)/lim - 1;
		}
		cout << res << "\n";
	}
	return 0;
}
