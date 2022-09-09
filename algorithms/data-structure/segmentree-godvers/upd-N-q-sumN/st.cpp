
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep  9 22:38:33 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// given array: base-0

#include <iostream>
using namespace std;

const int N = 1e5+7;
// cnt[i]: the number of nodes that `f[i]` manages
int n, h, q, f[N<<1], d[N], cnt[N<<1];

void init() {
	h = 32 - __builtin_clz(n);
	for (int i = 0; i < n; i++)
		cnt[i+n] = 1;
	for (int i = n-1; i > 0; i--)
		f[i] = f[i<<1] + f[i<<1|1], 
		cnt[i] = cnt[i<<1] + cnt[i<<1|1];
}

void assign(int i, int v) {
	f[i] += v*cnt[i];
	if (i < n) d[i] += v;
}

void pull(int i0) {
	// pull from top to i0
	for (int x = h, i = i0>>x; x > 0; i = i0>>(--x)) {
		assign(i<<1  , d[i]);
		assign(i<<1|1, d[i]);
		d[i] = 0;
	}
}

void push(int i) {
	// push from i to top
	for (i>>=1; i > 0; i>>=1)
		f[i] = f[i<<1] + f[i<<1|1] + d[i]*cnt[i];
}

void upd(int l, int r, int v) {
	int l0 = l+=n, r0 = r+=n;
	for (; l < r; l>>=1, r>>=1) {
		if (l&1) assign(l++, v);
		if (r&1) assign(--r, v);
	}
	push(l0); push(r0-1);
}

int get(int l, int r) {
	pull(l+=n); pull((r+=n)-1);
	int res = 0;
	for (; l < r; l>>=1, r>>=1) {
		if (l&1) res += f[l++];
		if (r&1) res += f[--r];
	}
	return res;
}

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> f[i+n];
	init();
	//
	while (true) {
		char t;
		int l, r, v;
		cin >> t;
		if (t == 'u') {
			cin >> l >> r >> v;
			upd(l, r, v);
		} else if (t == 'q') {
			cin >> l >> r;
			cout << get(l, r) << "\n";
		}
	}
	return 0;
}
