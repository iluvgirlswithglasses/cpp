
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Jan 16 22:35:07 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
need fix:
tách m3 query vòng sang thành 2 query đi
bruh
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/**
 * @ defs
 * */
#define all(c) c.begin(), c.end()
const int N = 1e9+7, M = 1e5+7;

struct query {
	int l0, r0, l, r;
};

/**
 * @ vars
 * */
int n, m;
query qr[M];
vector<int> p;		// p[i]: vị trí bé thứ i trong số các query
int f[M<<2], fn;	// segtree

/**
 * utils
 * */
void compress() {
	set<int> s;
	for (int i = 0; i < m; i++)
		s.insert(qr[i].l0), s.insert(qr[i].r0);
	p.assign(s.begin(), s.end());
	fn = p.size();
	//
	for (int i = 0; i < m; i++) {
		qr[i].l = lower_bound(all(p), qr[i].l0) - p.begin();
		qr[i].r = lower_bound(all(p), qr[i].r0) - p.begin() + 1;
	}
	p.push_back(n+1);
}

/**
 * @ segtree
 * */
void upd(int l, int r) {
	for (l+=fn, r+=fn; l < r; l>>=1, r>>=1) {
		if (l&1) f[l++]++;
		if (r&1) f[--r]++;
	}
}

int get(int p) {
	int res = 0;
	for (p+=fn; p > 0; p>>=1)
		res += f[p];
	return res;
}

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// inp
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> qr[i].l0 >> qr[i].r0;
	}
	// calc
	compress();
	for (int i = 0; i < m; i++) {
		int l = qr[i].l, r = qr[i].r;
		if (l < r) {
			upd(l, r);
		} else {
			upd(l, fn);
			upd(0, r);
		}
	}
	// out
	vector<int> v(fn);
	for (int i = 0; i < fn; i++)
		v[i] = get(i);
	int mx = *max_element(all(v)), cnt = 0;
	for (int i = 0; i < fn; i++) if (v[i] == mx) {
		cnt += p[i+1] - p[i];
	}
	cout << mx << " " << cnt << "\n";
	// debug
	for (int i: p) cout << i << " "; cout << "\n";
	for (int i: v) cout << i << " "; cout << "\n";
	return 0;
}
