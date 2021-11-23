
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Nov 23 10:59:56 2021
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

const int N = 1e4+7;
const int T = 14143+7;
// m: len of u[]
int n, m, a[N], u[T];

/**
 * the sequence u[]
 * */
void gen_u(int mx) {
	int i;
	for (i = 1; u[i-1] < mx; i++) {
		u[i] = u[i-1] + i;
	}
	m = i;
}

bool in_u(int x) {
	int l = 1, r = m-1;
	while (l < r) {
		int mi = (l + r + 1) >> 1;
		if (x >= u[mi]) {
			l = mi;
		} else {
			r = mi - 1;
		}
	}
	return u[l] == x;
}

/**
 * drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	gen_u(*max_element(a, a+n));
	//
	int cr = in_u(a[0]), res = cr;
	for (int i = 1; i < n; i++) {
		if (in_u(a[i])) {
			if (a[i] >= a[i-1]) {
				res = max(res, ++cr);
			} else {
				cr = 1;
				res = max(res, 1);
			}
		} else {
			cr = 0;
		}
	}
	cout << res << "\n";
	return 0;
}
