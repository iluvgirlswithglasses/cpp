#include <iostream>
using namespace std;

/*
https://vnoi.info/wiki/translate/codeforces/Efficient-and-easy-segment-trees.md

applications:
	vnoj/lites.cpp
	vnoj/qtreex.cpp
*/

#define u32 unsigned int

const u32 N = 1e5+7, I = 2e9+7;
u32 n, h;
int t[N<<1], d[N];

/**
 * utils
 * */
void assign(int i, int v) {
	t[i] += v;
	if (i < n) d[i] += v;
}

void push(int i) {
	for (i >>= 1; i > 0; i >>= 1) {
		t[i] = max(t[i<<1], t[i<<1|1]) + d[i];
	}
}

void pull(int p) {
	for (int _i=h, i=p>>_i; _i > 0; _i--, i=p>>_i) {
		//
		assign(i<<1, d[i]); 
		assign(i<<1|1, d[i]);
		d[i] = 0;
	}
}

/**
 * main
 * */
void update(u32 l, u32 r, int v) {
	l += n; u32 l0 = l;
	r += n; u32 r0 = r;
	for (; l < r; l>>=1, r>>=1) {
		if (l&1) assign(l++, v);
		if (r&1) assign(--r, v);
	}
	push(l0); push(r0-1);
}

int query(u32 l, u32 r) {
	l+=n; pull(l); 
	r+=n; pull(r-1);
	//
	int res = -I;
	for (; l < r; l>>=1, r>>=1) {
		if (l&1) res = max(res, t[l++]);
		if (r&1) res = max(res, t[--r]);
	}
	return res;
}

/**
 * drivers
 * */
int main() {
	cin >> n;
	h = 32 - __builtin_clz(n);
	for (u32 i = 0; i < n; i++)
		cin >> t[n+i];
	for (u32 i = n-1; i > 0; i--)
		t[i] = max(t[i<<1], t[i<<1|1]);
	//
	char typ;
	u32 l, r;
	int v;
	while (true) {
		cin >> typ;
		if (typ == 'u') {
			cin >> l >> r >> v;
			update(l, r, v);
		} else if (typ == 'q') {
			cin >> l >> r;
			cout << query(l, r) << "\n";
		}
	}
}
