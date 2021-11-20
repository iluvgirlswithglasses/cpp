
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 20 15:15:00 2021
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
const int N = 2e5+7;
int n, a[N];
ll  s, cnt[N], res[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	//
	for (int i = 1; i <= n; i++) if (cnt[i] >= 2) {
		res[i] = cnt[i] * (cnt[i] - 1) >> 1;
		s += res[i];
	}
	//
	for (int i = 0; i < n; i++) {
		ll c = cnt[a[i]] - 1;
		if (c < 2) {
			c = 0;
		} else {
			c = c * (c-1) >> 1;
		}
		cout << s - res[a[i]] + c << "\n";
	}
	return 0;
}
