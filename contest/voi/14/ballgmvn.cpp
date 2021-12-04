
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Dec  4 17:41:59 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cmath>
#include <cfloat>
#include <vector>
#include <set>
using namespace std;

#define ld long double

/**
 * defs
 * */
struct point {
	int x, y;
};

struct pack {
	ld d;
	int idx, x, y;

	pack(int i, point& p, point& o) {
		idx = i;
		y = (p.y - o.y), x = (p.x - o.x);
		if (x == 0) {
			d = LDBL_MAX;
		} else {
			d = (ld) y / x;
		}
	}

	bool operator < (const pack& p) const {
		return d < p.d;
	}
};

/**
 * drivers
 * */
point arr[2][1002];

bool calc(int n, int chose_color, int chose_idx) {
	point o = arr[chose_color][chose_idx];
	// dời gốc tọa độ sang bi được chọn
	// hỏi xem có 2 bi khác màu nào tạo thành cùng 1 góc với trục tọa độ hay k
	vector<pack> v[2];
	for (int i = 0; i < 2; i++)
	for (int j = 0; j < n; j++)
	if (chose_color != i || chose_idx != j) {
		v[i].push_back(pack(j, arr[i][j], o));
	}
	set<pack> s(v[1].begin(), v[1].end());
	//
	for (int i = 0; i < v[0].size(); i++) {
		pack& cr = v[0][i];
		set<pack>::iterator p = s.find(cr);
		if (p != s.end()) {
			//
			int x = chose_idx + 1 + chose_color*n, y = cr.idx+1, z = n + 1 + p->idx;
			cout << x << " " << y << " " << z << "\n";
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[0][i].x >> arr[0][i].y;
	for (int i = 0; i < n; i++)
		cin >> arr[1][i].x >> arr[1][i].y;
	//
	for (int i = 0; i < n; i++) {
		if (calc(n, 0, i)) return 0;
	}
	for (int i = 0; i < n; i++) {
		if (calc(n, 1, i)) return 0;
	}
	cout << -1 << "\n";
	return 0;
}
