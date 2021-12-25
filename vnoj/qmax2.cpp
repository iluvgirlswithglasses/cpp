
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Dec 24 21:17:36 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

/** vars */
const int N = 5e4+7;
int n, h, f[N<<1], d[N];

/** segtree utils */
void assign(int i, int v) {
	if (i < n) d[i] += v;
	f[i] += v;
}

void push(int p) {
	for (int x=h, i=p>>x; x > 0; x--, i=p>>x) {
		assign(i<<1, d[i]);
		assign(i<<1|1, d[i]);
		d[i] = 0;
	}
}

void build(int p) {
	for (p>>=1; p > 0; p>>=1) {
		f[p] = max(f[p<<1], f[p<<1|1]) + d[p];
	}
}

/** segtree */
void upd(int l, int r, int k) {
	int l0 = (l += n);
	int r0 = (r += n);
	for (; l < r; l>>=1, r>>=1) {
		if (l&1) assign(l++, k);
		if (r&1) assign(--r, k);
	}
	build(l0);
	build(r0-1);
}

int get(int l, int r) {
	l += n; push(l);
	r += n; push(r);
	int res = 0;
	for (; l < r; l>>=1, r>>=1) {
		if (l&1) res = max(res, f[l++]);
		if (r&1) res = max(res, f[--r]);
	}
	return res;
}

/** drivers */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q; cin >> n >> q;
	h = 32 - __builtin_clz(n);
	//
	while (q--) {
		int t, x, y, k;
		cin >> t >> x >> y;
		if (t == 0) {
			cin >> k;
			upd(x-1, y, k);
		} else {
			cout << get(x-1, y) << "\n";
		}
	}
	return 0;
}
