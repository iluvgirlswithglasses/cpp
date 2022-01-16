
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Jan 16 09:42:44 2022
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
const int N = 1e7+7;

ll n, m, k, x, q, f[N<<1], d[N];

void build() {
	for (int i = n-1; i > 0; i--)
		f[i] = max(f[i<<1], f[i<<1|1]);
}

void assign(int p, int v) {
	f[p] += v;
	if (p < n) d[p] += v;
}

void inherit(int p) {
	for (p>>=1; p > 0; p>>=1) {
		f[p] = max(f[p<<1], f[p<<1|1]) + d[p];
	}
}

void upd(int l, int r, int d) {
	int l0 = (l+=n), r0 = (r+=n);
	for (; l < r; l>>=1, r>>=1) {
		if (l&1) assign(l++, d);
		if (r&1) assign(--r, d);
	}
	inherit(l0); inherit(r0-1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k >> x >> q;
	f[n] = x;
	for (int i = 1; i < n; i++)
		f[n+i] = (f[n+i-1] * k) % m;
	for (int i = 0; i < n; i++)
		f[n+i] -= q;
	build();
	//
	int t; cin >> t;
	while (t--) {
		int l, r, d;
		cin >> l >> r >> d;
		upd(l-1, r, -d);
		cout << f[1] << "\n";
		upd(l-1, r, d);
	}
	return 0;
}
