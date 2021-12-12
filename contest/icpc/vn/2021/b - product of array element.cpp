
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Dec 12 21:29:44 2021
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
const int N = 1e3+7;
const ll  R = 1e9+7;
int n, pos, neg, zero;
ll  a[N];

ll calc(int k) {
	ll res = 1;
	for (int i = 0; i < n; i++) if (i != k) {
		res *= a[i];
		res %= R;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) 
			neg++;
		else if (a[i] > 0) 
			pos++;
		else 
			zero++;
	}
	//
	if (zero > 1) {
		cout << 0 << "\n";
	} else if (neg&1) {
		int idx;
		ll mx = -2e9;
		for (int i = 0; i < n; i++) if (a[i] < 0 && a[i] > mx) {
			mx = a[i];
			idx = i;
		}
		cout << calc(idx) << "\n";
	} else if (zero == 1) {
		int i;
		for (i = 0; i < n; i++) if (a[i] == 0) {
			break;
		}
		cout << calc(i) << "\n";
	} else {
		cout << calc(-1) << "\n";
	}
	return 0;
}
