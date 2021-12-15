
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Dec 15 19:14:57 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 1e5+7;
int n, f[N<<1];

void build() {
	for (int i = n-1; i > 0; i--)
		f[i] = max(f[i<<1], f[i<<1|1]);
}

void upd(int p, int v) {
	f[p+=n] = v;
	for (p>>=1; p>0; p>>=1)
		f[p] = max(f[p<<1], f[p<<1|1]);
}

int get(int l, int r) {
	int res = -2e9;
	for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
		if (l&1) res = max(res, f[l++]);
		if (r&1) res = max(res, f[--r]);
	}
	return res;
}

int main() {
	freopen("COPHIEU.INP", "r", stdin);
	freopen("COPHIEU.OUT", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> f[i+n];
	build();
	int q; cin >> q;
	while (q--) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 0) {
			upd(a-1, b);
		} else {
			cout << get(a-1, b) << "\n";
		}
	}
	return 0;
}

