
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Oct 03 10:19:00 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e6+7, I = 1e9+7;
int n, q, a[N], shift;

struct SumSegtree {
	ll f[N<<1];

	void init() {
		for (int i = 0; i < n; i++)
			f[i+n] = a[i];
		for (int i = n-1; i > 0; i--)
			f[i] = f[i<<1] + f[i<<1|1];
	}

	void upd(int i, ll v) {
		f[i+=n] = v;
		for (i>>=1; i > 0; i>>=1)
			f[i] = f[i<<1] + f[i<<1|1];
	}

	ll get(int l, int r) {
		ll res = 0;
		for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
			if (l&1) res += f[l++];
			if (r&1) res += f[--r];
		}
		return res;
	}
} sst;

struct MinSegtree {
	struct CmpObj {
		// compare object
		int v, i, cr_index;

		bool operator < (const CmpObj &x) const {
			if (v == x.v)
				return cr_index < x.cr_index;
			return v < x.v;
		}
	};

	pi f[N<<1];

	void init() {
		for (int i = 0; i < n; i++)
			f[i+n] = {a[i], i};
		for (int i = n-1; i > 0; i--)
			f[i] = min(f[i<<1], f[i<<1|1]);
	}

	void upd(int i, int v) {
		f[i+n] = {v, i};
		for ((i+=n)>>=1; i > 0; i>>=1)
			f[i] = min(f[i<<1], f[i<<1|1]);
	}

	CmpObj mkobj(int i) {
		CmpObj x;
		x.v = f[i].st; 
		x.i = f[i].nd;
		x.cr_index = (f[i].nd + shift) % n;
		return x;
	}

	pi get(int l, int r) {
		CmpObj res = {I, I, I};
		for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
			if (l&1) res = min(res, mkobj(l++));
			if (r&1) res = min(res, mkobj(--r));
		}
		return {res.v, res.i};
	}
} mst;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sst.init();
	mst.init();
	while (q--) {
		int t; cin >> t;
		switch (t) {
			case 1: {
				int d; cin >> d;
				shift += d;
				if (shift >= n) shift -= n;
				break;
			}
			case 2: {
				int s, e, p; cin >> s >> e >> p;
				s = (s-1 - shift + n) % n;
				e = (e-1 - shift + n) % n;
				pi replaced;
				if (s <= e)
					replaced = mst.get(s, e+1);
				else
					replaced = min(mst.get(s, n), mst.get(0, e+1));
				mst.upd(replaced.nd, p);
				sst.upd(replaced.nd, p);
				break;
			}
			case 3: {
				int s, e; cin >> s >> e;
				s = (s-1 - shift + n) % n;
				e = (e-1 - shift + n) % n;
				if (s <= e) {
					cout << sst.get(s, e+1) << "\n";
				} else {
					cout << sst.get(s, n) + sst.get(0, e+1) << "\n";
				}
				break;
			}
		}
	}
	return 0;
}
