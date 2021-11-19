
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Nov 19 20:43:32 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

/** vars and constraints */
#define ll long long
const int N = 2e5+7;
int n, h[N], a[N];

/** fenwick tree */
ll f[N];

void upd(int h, ll v) {
	// những cây lớn hơn
	// có quyền xài kết quả từ cây nhỏ hơn
	for (; h <= n; h += h&-h) {
		f[h] = max(f[h], v);
	}
}

ll get(int h) {
	ll res = 0;
	for (; h >= 1; h -= h&-h) {
		res = max(res, f[h]);
	}
	return res;
}

/** drivers */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> h[i];
	for (int i = 0; i < n; i++) cin >> a[i];
	//
	for (int i = 0; i < n; i++) {
		upd(h[i], get(h[i]) + a[i]);
	}
	cout << get(n) << "\n";
	return 0;
}

