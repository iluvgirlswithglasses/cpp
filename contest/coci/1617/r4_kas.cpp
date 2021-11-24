
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Nov 24 15:46:42 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 502, S = 1e5+7, I = 1e9+7;
/*
dp[i][d] dùng để lưu lại kết quả của recursion(i, d)

dp special codes:
-1	not cached
-I	illegal
*/
int n, s, a[N], dp[N][S>>1];

/**
 * @utils
 * */
int max(int a, int b, int c) {
	return max(a, max(b, c));
}

/**
 * @perf
 * 
 * gọi	x là tổng số tiền của người cầm nhiều tiền hơn ở lượt i,
 * 		y là                  người cầm ít tiền hơn ở lượt i,
 * gọi	d = x - y
 * 		nói cách khác, d là độ lệch tiền
 * 
 * --> nếu d == 0 ở lượt n thì coi như tìm được 1 cách
*/
int recursion(int i, int d) {
	// tất nhiên không thể lệch tiền đến mức này 
	if ((d<<1) > s) return -I;
	// tui vẫn chưa biết cách gọi đệ quy + memory này là gì
	// nhưng thôi tạm gọi = cache
	int& cache = dp[i][d];
	if (cache != -1) return cache;
	// 
	if (i == n) {
		// được 1 cách
		if (d == 0)
			cache = 0;
		// cách chọn này bể
		else
			cache = -I;
		return cache;
	}

	// reminder:
	// khi 1 recursion bị bể,
	// nó sẽ trả về trừ vô cùng
	// & cache sẽ không nhận giá trị đó

	// trường hợp không bao giờ bị bể là skip tất cả, recursion(0, 0) returns 0

	cache = max(
		// đem đồng này đi đánh bạc thỏa
		// -->	x không cần tăng (+0)
		recursion(i+1, d) + 0,

		// đút đồng này vào x,
		// độ lệch tiền tăng lên a[i] thỏa
		// -->	x tăng lên a[i]
		recursion(i+1, d + a[i]) + a[i],

		// đút đồng này vào y
		d >= a[i] ? 
			// case x >= y + a, 
			// lượt i+1 x y không đổi chủ
			// x lượt này k tăng lên đồng nào
			recursion(i+1, d - a[i]) : 
			// case x < y + a,
			// lượt i+1 x y đổi chủ
			// -->	x lượt này == y lượt kế
			//		x = y + d
			// -->	x + a = y + a + d
			// -->	x + a - d = y + a
			// -->	y lượt kế = x + a - d
			recursion(i+1, a[i] - d) + a[i] - d
	);
	return cache;
}

/**
 * @drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// -1 == 111...1, so this memset will work fine
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	//
	int res = recursion(0, 0);
	res += s - (res<<1);
	cout << res << "\n";
	return 0;
}
