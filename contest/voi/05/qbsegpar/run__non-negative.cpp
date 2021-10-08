
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 08 10:00:27 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e4, I = 5e8;
// p[]: prefix array of a[]
// mx:  max possible continuous sum of a[]
int n, k, mx, a[N], p[N];

bool valid(int m, int k) {
	int bind = 0;
	int i = 1;
	for (; i <= n && k > 0; i++) {
		// min(m) == max(a[])
		// --> đảm bảo có ít nhất một phần tử mỗi phân đoạn
		if (p[i] - p[bind] > m) {
			k--;
			bind = i-1;
		}
	}
	return i == n+1 && k > 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1, kadane=0; i <= n; i++) {
		cin >> a[i];
		p[i] = p[i-1] + a[i];
		//
		kadane += a[i];
		if (kadane > mx) mx = kadane;
		if (kadane < 0) kadane = 0;
	}
	//
	int l = *max_element(a, a+n), r = mx, m;
	while (l < r) {
		m = (l + r) >> 1;
		// nếu tồn tại cách chia sao cho mỗi tổng đều <= m
		// --> TXĐ (l:m]
		// nếu không tồn tại
		// --> TXĐ (m:r]
		if (valid(m, k)) {
			r = m;
		} else {
			l = m+1;
		}
	}
	cout << r << "\n";
	return 0;
}

