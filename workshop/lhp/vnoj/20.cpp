
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Jan 14 13:59:58 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * @ defs
 * */
#define ll long long
const int N = 1e5+7;

struct event {
	int d, t, x, v;

	event(int _d, int _t, int _x, int _v) {
		d = _d, t = _t, x = _x, v = _v;
	}

	bool operator < (const event& e) const {
		if (x == e.x) return v < e.v;
		return x < e.x;
	}
};

/**
 * @ segtree
 * */
int s[N<<2], d[N<<2];

struct segtree {

	void inherit(int l, int r, int idx) {
		if (d[idx]) 
			// node này có 1 đoạn [l:r] active, ghi lại độ dài r - l
			s[idx] = r - l;
		else 
			// xài ké
			s[idx] = (l < r ? s[(idx<<1) + 1] + s[(idx<<1) + 2] : 0);
	}

	void upd(int l, int r, int ql, int qr, int v, int idx) {
		if (ql <= l && r <= qr) {
			// [l: r] con [ql, qr] --> node này nhận / bớt 1 line
			d[idx] += v;
		} else {
			int m = (l + r) >> 1, lchild = (idx<<1) + 1, rchild = (idx<<1) + 2;
			if (qr <= m) 
				upd(l, m, ql, qr, v, lchild);
			else if (m <= ql) 
				upd(m, r, ql, qr, v, rchild);
			else {
				upd(l, m, ql, m, v, lchild);
				upd(m, r, m, qr, v, rchild);
			}
		}
		//
		inherit(l, r, idx);
	}
} f;

/**
 * @ drivers
 * */
int n;
vector<event> e;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		// chuyển hết sang verticle
		// cho nó giống bài trước
		e.push_back(event(0, y1, x1, 1));
		e.push_back(event(0, y1, x2, -1));
	}
	sort(e.begin(), e.end());
	//
	ll res = 0, pre = 0;
	for (event& e: e) {
		// s[0] == tổng độ dài các verticle lines đg active
		res += s[0] * (e.x - pre);
		f.upd(0, 100002, e.d, e.t, e.v, 0);
		pre = e.x;
	}
	cout << res << "\n";
	return 0;
}
