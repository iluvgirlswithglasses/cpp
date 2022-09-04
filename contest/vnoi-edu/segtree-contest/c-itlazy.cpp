
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Sep  4 16:21:26 2022
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
const int N = 1e5+7;
int n, h, q;
ll  f[N<<1], d[N];

void assign(int i, ll v) {
	f[i] += v;
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
		f[i] = max(f[i<<1], f[i<<1|1]) + d[i];
}

void upd(int l, int r, ll v) {
	int l0 = l+=n, r0 = r+=n;
	for (; l < r; l>>=1, r>>=1) {
		if (l&1) assign(l++, v);
		if (r&1) assign(--r, v);
	}
	push(l0); push(r0-1);
}

ll get(int l, int r) {
	pull(l+=n); pull((r+=n)-1);
	ll res = -1e18-7;
	for (; l < r; l>>=1, r>>=1) {
		if (l&1) res = max(res, f[l++]);
		if (r&1) res = max(res, f[--r]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	h = 32 - __builtin_clz(n);
	for (int i = 0; i < n; i++)
		cin >> f[i+n];
	for (int i = n-1; i > 0; i--)
		f[i] = max(f[i<<1], f[i<<1|1]);
	//
	cin >> q;
	while (q--) {
		int t, a, b, c;
		cin >> t;
		if (t == 1) {
			cin >> a >> b >> c;
			upd(a-1, b, c);
		} else {
			cin >> a >> b;
			cout << get(a-1, b) << "\n";
		}
	}
	return 0;
}
