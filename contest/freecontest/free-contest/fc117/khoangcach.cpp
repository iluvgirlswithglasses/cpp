
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Nov 17 14:31:24 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
Xét 2 điểm i j với Xi > Xj có:
	d(i, j) = 0 		nếu Vj > Vi
	d(i, j) = Xi - Xj 	nếu Vj <= Vi
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/**
 * def
 */
#define ll long long
const int N = 1e5+7;
const int I = 1e8+7;

struct point {
	// c: giá trị của v sau compress
	int x, v, c;
};

/**
 * points
 */
int n;
point a[N];

void compress() {
	set<int> s;
	for (int i = 0; i < n; i++) {
		s.insert(a[i].v);
	}
	vector<int> v(s.begin(), s.end());
	//
	for (int i = 0; i < n; i++) {
		// starts at 0
		a[i].c = lower_bound(v.begin(), v.end(), a[i].v) - v.begin();
	}
}

/**
 * segment tree
 *
   get(l, r) trả về tổng khoảng cách giữa các điểm:
       a[j].x có a[j].c thuộc [l:r)
   với điểm I

   gọi tổng đó là S, và số số hạng a[j].x là C

   --> tổng d(i, j) với i là điểm cố định, còn j là các điểm có a[j].x < a[i].x
   ==  S - (I - a[i].x)*C		# getf trả về cái này luôn
 */
ll  f[N<<1];
int g[N<<1];	// g[i]: số points đang được node i trong segment tree quản lý

ll getf(int l, int r, int x) {
	ll res = 0, cnt = 0;
	for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if (l&1) {
			res += f[l], cnt += g[l];
			l++;
		}
		if (r&1) {
			--r;
			res += f[r], cnt += g[r];
		}
	}
	return res - (I - x) * cnt;
}

void upd(int i, int x) {
	int d = I - x;
	for (i+=n; i > 0; i>>=1) {
		f[i] += d;
		g[i]++;
	}
}

/**
 * drivers
 */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].x;
	for (int i = 0; i < n; i++) cin >> a[i].v;
	//
	sort(a, a+n, [](point& i, point& j){
		return i.x < j.x;
	});
	compress();
	// 
	ll res = 0;
	for (int i = 0; i < n; i++) {
		res += getf(0, a[i].c+1, a[i].x) ;
		upd(a[i].c, a[i].x);
		//
	}
	cout << res << '\n';
	return 0;
}

