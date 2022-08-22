
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Oct 07 19:16:02 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define u64 unsigned long long
const u64 N = 1e5+7, L = 1e9+7, I = 1.2e17;
// đổi `L` thành `c`
u64 n, c, a[N], b[N];

// ý tưởng này giống bfc06/pottery nhỉ
bool valid(u64 h) {
	u64 needed = 0;
	for (int i = 0; i < n; i++) {
		// thiếu dòng này & chết 4 test
		if (h <= a[i]) continue;
		// (b[i] - 1): làm tròn lên
		u64 add = (h - a[i] + b[i] - 1) / b[i];
		needed += add;
	}
	return needed <= c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	// bs chiều cao của cây
	u64 l = 0, r = I, m;
	while (l < r) {
		m = (l + r + 1) >> 1;
		if (valid(m)) {
			l = m;
		} else {
			r = m-1;
		}
	}
	cout << l << "\n";
	return 0;
}

