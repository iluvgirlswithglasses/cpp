
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Oct 04 16:48:49 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e4+7, C = 1e3+7, I = 1e9+7;
// c: giá tiền của cái máy đắt nhất
// d[i]: phạm vi hoạt động của cái máy có giá tiền `i`
// dp[i]: giá tiền tối thiểu để hút đến chiếc lá thứ `i`
// dp[i] >= dp[i-1] mọi `i`
int n, m, c, x[N], d[C], dp[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(dp, I, sizeof(dp));
	dp[0] = 0;
	//
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	sort(x+1, x+1+n);
	//
	for (int i = 0; i < m; i++) {
		int range, cost;
		cin >> range >> cost;
		// tầm hoạt động của máy == 2d+1
		d[cost] = max(d[cost], range<<1|1);
		c = max(c, cost);
	}
	// th đặc biệt
	if (d[0] > 0) {
		cout << 0 << "\n";
		return 0;
	}
	//
	for (int i = 1; i <= n; i++) {
		// thử hút lá thứ `i` với máy mang giá tiền `j`
		for (int j = 1; j <= c; j++) if (d[j] > 0) {
			int l = 1, r = i;
			while (l < r) {
				int m = (l + r) >> 1;
				if (x[i] - x[m] + 1 <= d[j]) {
					r = m;
				} else {
					l = m+1;
				}
			}
			dp[i] = min(dp[i], dp[r-1] + j);
		}
	}
	//
	cout << dp[n] << "\n";
	return 0;
}

