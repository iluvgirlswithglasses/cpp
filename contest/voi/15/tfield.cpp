
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Dec  8 13:55:33 2021
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
 *
 * đa giác có S lớn -> auto lồng đa giác có S nhỏ
 * */
#define ll long long

struct Point {
	int x, y;

	Point(int a, int b) {
		x = a, y = b;
	}
};

struct Area {
	ll s;	// 2 lần diện tích của khoang này
	int c;

	void calc_s(vector<Point>& p) {
		int n = p.size();
		for (int i = 0; i < n-1; i++)
			s += (ll) (p[i].x - p[i+1].x) * (p[i].y + p[i+1].y);
		s += (ll) (p[n-1].x - p[0].x) * (p[n-1].y + p[0].y);
		s = abs(s);
	}
};

/**
 * @
 * */
ll calc(int c, int k, vector<Area>& chosen) {
	// chuyển hết tcả về màu c
	int n = chosen.size();
	// f[i]: số khoang cần đổi sang màu c
	vector<int> f(n);
	f[0] = chosen[0].c != c;
	for (int i = 1; i < n; i++)
		f[i] = f[i-1] + (chosen[i].c != c);
	//
	ll res = 0;
	for (int l = 0, r = 0; r < n; r++) {
		while (f[r] - (l == 0 ? 0 : f[l-1]) > k) l++;
		res = max(res, chosen[r].s - (l == 0 ? 0 : chosen[l-1].s));
	}
	return res;
}

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int m, k;
	cin >> m >> k;
	vector<Area> area(m);
	//
	for (int i = 0; i < m; i++) {
		//
		int n, c, x, y;
		cin >> n >> c;
		area[i].c = c-1;
		//
		vector<Point> p;
		for (int j = 0; j < n; j++) {
			cin >> x >> y;
			p.push_back(Point(x, y));
		}
		area[i].calc_s(p);
	}
	// sort các khoang từ trong ra ngoài
	// giờ thì dp, tìm cách chọn <= k khoang
	sort(area.begin(), area.end(), [](Area& i, Area& j){
		return i.s < j.s;
	});
	//
	ll res = 0;
	for (int i = 0; i < m; i++)
		res = max(res, calc(i, k, area));
	cout << (res>>1);
	if (res&1) {
		cout << ".5\n";
	} else {
		cout << ".0\n";
	}
	return 0;
}
