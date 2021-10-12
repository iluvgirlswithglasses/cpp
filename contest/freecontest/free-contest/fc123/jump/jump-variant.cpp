
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Oct 12 09:50:42 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

// giả sử đề bài đổi thành:
// từ cột `x` muốn nhảy sang cột `y` nào thì nhảy
// miễn là `h[x]` < `h[y]`
// thì đây là cách giải cho bài tập đó

#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int N = 1e5+7;
// dp[i]: số bước nhảy tối đa có thể thực hiện khi đứng ở cột i
int n, q, a[N], dp[N];

/**
 * utils
 * */
void compress() {
	set<int> s(a, a+n);
	vector<int> v(s.begin(), s.end());
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
}

/**
 * fenwick
 * */
int f[N];

int get(int h) {
	int res = 0;
	for (; h <= n; h += h&-h) {
		res = max(res, f[h]);
	}
	return res;
}

void upd(int h, int v) {
	for (; h > 0; h -= h&-h) {
		f[h] = max(f[h], v);
	}
}

/**
 * perf
 * */
void gendp() {
	int premax = 0;
	for (int i = n-1; i >= 0; i--) {
		if (a[i] < premax)
			dp[i] = get(a[i]) + 1;
		premax = max(premax, a[i]);
		upd(a[i]-1, dp[i]);
	}
}

/**
 * drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	compress();
	gendp();
	//
	for (int i = 0; i < q; i++) {
		int v; cin >> v;
		cout << dp[v-1] << "\n";
	}
	return 0;
}

