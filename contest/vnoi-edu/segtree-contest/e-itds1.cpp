
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Sep  4 20:53:57 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <set>
using namespace std;

#define all(c) c.begin(), c.end()

const int N = 1e5+7, I = 1e9+7;
int n, q;
multiset<int> f[N<<1];

void check(int &res, int i, int k) {
	multiset<int>::iterator p = f[i].lower_bound(k);
	if (p != f[i].end()) res = min(res, *p);
}

void upd(int i, int v) {
	int u = *f[i+=n].begin();
	for (; i > 0; i>>=1) 
		f[i].erase(u), f[i].insert(v);
}

int get(int l, int r, int k) {
	int res = I;
	for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if (l&1) check(res, l++, k);
		if (r&1) check(res, --r, k);
	}
	return res == I ? -1 : res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 0, a; i < n; i++) {
		cin >> a; f[i+n].insert(a);
	}
	for (int i = n-1; i > 0; i--) {
		f[i].insert(all(f[i<<1  ]));
		f[i].insert(all(f[i<<1|1]));
	}
	//
	while (q--) {
		int t, a, b, c; cin >> t;
		if (t == 1) {
			cin >> a >> b;
			upd(a-1, b);
		} else {
			cin >> a >> b >> c;
			cout << get(a-1, b, c) << "\n";
		}
	}
	return 0;
}
