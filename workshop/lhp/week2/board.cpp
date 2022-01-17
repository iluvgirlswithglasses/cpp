
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Jan 17 08:58:39 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @ defs
 * */
#define all(c) c.begin(), c.end()
const int N = 1e3+7, I = 1e6+7;

struct event {
	static const int OPEN = 1, CLOSE = -1;

	// down, top, x, v
	int d, t, x, v;

	event(int _d, int _t, int _x, int _v) {
		d = _d, t = _t, x = _x, v = _v;
	}

	bool operator < (const event& e) const {
		// OPEN typ được ưu tiên hơn CLOSE typ
		if (x == e.x) return v > e.v;
		return x < e.x;
	}
};

/**
 * @ segtree
 * */
struct segtree {

	vector<int> s, d;

	segtree(int n) {
		s.resize(n<<1, 0);
		d.resize(n<<1, 0);
	}

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

	int query() {
		return s[0];
	}
} st(I);

/**
 * @ vars
 * */
int w, h, n;
vector<event> events;

/**
 * @ drivers
 * */
void getinp() {
	cin >> w >> h >> n;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; 
		cin >> x1 >> y1 >> x2 >> y2;
		// chuyển hết sang verticle
		events.push_back(event(y1, y2, x1, event::OPEN));
		events.push_back(event(y1, y2, x2, event::CLOSE));
	}
	// làm giả mấy anh này
	// coi như là 2 vạch ở 2 biên
	events.push_back(event(0, h, 0, event::OPEN));
	events.push_back(event(0, h, 0, event::CLOSE));
	events.push_back(event(0, h, w, event::OPEN));
	events.push_back(event(0, h, w, event::CLOSE));
	sort(all(events));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	getinp();
	// driver's vars
	int res = 0;
	bool coloring = false;
	//
	for (event& e: events) {
		st.upd(0, I, e.d, e.t, e.v, 0);
		if (st.query() == h) {
			if (coloring) res++;
			coloring = false;
		} else {
			coloring = true;
		}
	}
	cout << res << "\n";
	return 0;
}
