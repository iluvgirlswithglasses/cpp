
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Nov 29 16:47:09 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

// I'd code a double queue method later

/** def & vars */
const int N = 1e6+7, I = 2e9+7;
int n, m, c, cnt;

/** segment tree */
int mn[N<<1], mx[N<<1];

void build() {
	for (int i = n-1; i >= 1; i--) {
		mn[i] = min(mn[i<<1], mn[i<<1|1]);
		mx[i] = max(mx[i<<1], mx[i<<1|1]);
	}
}

int minquery(int l, int r) {
	int res = I;
	for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if (l&1) res = min(res, mn[l++]);
		if (r&1) res = min(res, mn[--r]);
	}
	return res;
}

int maxquery(int l, int r) {
	int res = 0;
	for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if (l&1) res = max(res, mx[l++]);
		if (r&1) res = max(res, mx[--r]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> c;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		mn[i+n] = mx[i+n] = a;
	}
	build();
	for (int l = 0, r = m; r <= n; l++, r++) {
		if (maxquery(l, r) - minquery(l, r) <= c) {
			cout << l+1 << "\n";
			cnt++;
		}
	}
	//
	if (cnt == 0) cout << "NONE\n";
	return 0;
}
