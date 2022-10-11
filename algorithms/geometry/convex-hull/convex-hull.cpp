
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Oct 11 18:04:17 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// about this monotone chain implementation:
// https://vnoi.info/wiki/translate/wcipeg/Convex-Hull.md

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
	double x, y;

	bool operator < (const point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

bool clockwise(point &a, point &b, point &c) {
	// a -> b -> c đi theo thứ tự xuôi chiều kim đồng hồ
	return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) < 0;
}

bool counter_clockwise(point &a, point &b, point &c) {
	// a -> b -> c đi theo thứ tự ngược chiều kim đồng hồ
	return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) > 0;
}

vector<point> calc(vector<point> &a) {
	if (a.size() == 1)
		return vector<point>();
	sort(a.begin(), a.end());
	//
	vector<point> res, up, down;	// kquả, chuỗi trên, chuỗi dưới
	point left = a[0], right = a.back();
	up.push_back(left);
	down.push_back(left);
	//
	for (size_t i = 1; i < a.size(); i++) {
		// thêm vào chuỗi trên
		if (i == a.size() - 1 || clockwise(left, a[i], right)) {
			while (
				up.size() >= 2 && 
				!clockwise(up[up.size()-2], up[up.size()-1], a[i])
			) {
				up.pop_back();
			}
			up.push_back (a[i]);
		}
		// thêm vào chuỗi dưới
		if (i == a.size() - 1 || counter_clockwise(left, a[i], right)) {
			while (
				down.size() >= 2 && 
				!counter_clockwise(down[down.size()-2], down[down.size()-1], a[i])
			) {
				down.pop_back();
			}
			down.push_back (a[i]);
		}
	}
	// gộp
	for (size_t i = 0; i < up.size(); i++)
		res.push_back(up[i]);
	for (size_t i = down.size()-2; i > 0; i--)
		res.push_back(down[i]);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<point> a;
	for (int i = 0; i < n; i++)
		cin >> a[i].y >> a[i].x;
	vector<point> res = calc(a);
	for (point &p: res)
		cout << p.y << " " << p.x << "\n";
	return 0;
}
