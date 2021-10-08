
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 08 12:31:43 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * vars
 * */
const int N = 15e3+7, I = 5e8;
// p[]: prefix array của a[]
// c[]: p[] sau compress
//   m: số phần tử độc nhất trong p[]
int n, m, k, p[N], c[N];
//   v: p[] sau khi đã sort
vector<int> v;


/**
 * utils
 * */
vector<int> compress() {
	set<int> s(p, p+1+n);	// bao gồm 0
	vector<int> v(s.begin(), s.end());
	for (int i = 0; i <= n; i++) {
		c[i] = lower_bound(v.begin(), v.end(), p[i]) - v.begin() + 1;
	}
	return v;
}


/**
 * fenwich tree
 * 
 * dùng để hỗ trợ dp_min & dp_max
 * */
int f_min[N], f_max[N];

void min_upd(int i, int v) {
	for (; i > 0; i -= i&-i)
		f_min[i] = min(f_min[i], v);
}

void max_upd(int i, int v) {
	for (; i > 0; i -= i&-i)
		f_max[i] = max(f_max[i], v);
}

// lấy ra cách chia ít phân đoạn nhất
// từ những thằng >= i
int min_get(int i) {
	int res = I;
	for (; i <= m; i += i&-i)
		res = min(res, f_min[i]);
	return res;
}

// lấy ra cách chia nhiều phân đoạn nhất
// từ những thằng >= i
int max_get(int i) {
	int res = -I;
	for (; i <= m; i += i&-i)
		res = max(res, f_max[i]);
	return res;
}

void f_init() {
	// sai:
	// memset(f_min, I, (m+1)*sizeof(f_min[0]));	// I = 5e8
	// memset(f_max, -I, (m+1)*sizeof(f_max[0]));
	// đúng:
    for (int i = 0; i <= m; i++) {
        f_min[i] = I; 
        f_max[i] = -I;
    }
    //
	min_upd(c[0], 0);
	max_upd(c[0], 0);
}


/**
 * calc
 * */
// dp_min[i]:
// 		số tập tối thiểu để chia a[0..i] sao cho mỗi tập đều có tổng <= m
// dp_max[i]:
// 		số tập tối đa để chia a[0..i] sao cho mỗi tập đều có tổng <= m
int dp_min[N], dp_max[N];

bool valid(int m) {
	f_init();
	int mink = 0, maxk = 0;
	//
	for (int i = 1; i <= n; i++) {
		// p[i] - p[j] <= m
		// --> p[j] >= p[i] - m
		int rank_j = lower_bound(v.begin(), v.end(), p[i] - m) - v.begin() + 1;
		mink = min_get(rank_j) + 1;
		maxk = max_get(rank_j) + 1;
		min_upd(c[i], mink);
		max_upd(c[i], maxk);
		// debug
		// clog << i << " " << c[i] << " " << rank_j << " " << mink << " " << maxk << "\n";
	}
	return mink <= k && k <= maxk;
}


/**
 * drivers
 * */
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		p[i] += p[i-1];
	}
	v = compress();
	m = v.size();
	//
	int l = -I, r = I;
	while (l < r) {
		int m = (l + r) >> 1;
		// clog << "\n" << m << "\n";
		if (valid(m)) {
			r = m;
		} else {
			l = m+1;
		}
	}
	cout << r << "\n";
	return 0;
}

