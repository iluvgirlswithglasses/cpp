
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct  8 10:17:02 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5+7, I = 2e9+7;
int n, k, a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	//
	int res = I;
	for (int l = 0, r = k-1; r < n; l++, r++) {
		res = min(res, a[r] - a[l]);
	}
	cout << res << "\n";
	return 0;
}
