
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Aug 25 20:48:32 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
using namespace std;

// another LCS variant
// I just did bfc045/comsub.cpp and then this
// what a coincidence

const int N = 1e3+7, K = 12, R = 1e9+9;	// <<-- cái đm +9 chứ k fải +7
int n, m, k, a[N], b[N], dp[K][N][N];

int add(int a, int b) {
	int c = a + b;
	if (c >= R) return c - R;
	return c;
}

int sub(int a, int b) {
	int c = a - b;
	if (c < 0) return c + R;
	return c;
}

// > Thẻ bài có giá trị cao thứ k của Neko lớn hơn thẻ bài có giá trị cao thứ k của đối thủ.
// actually that's a distractor.

int calc() {
	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= m; j++) {
		dp[0][i][j] = 1;
	}
	for (int x = 1; x <= k; x++)
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		// just like bfc045/comsub.cpp
		dp[x][i][j] = sub(add(dp[x][i-1][j], dp[x][i][j-1]), dp[x][i-1][j-1]);
		if (a[i] > b[j]) {
			/**
			1:
				Có `x` dấu lớn hơn xảy ra
				--> Lá bài lớn thứ `y` của Neko có giá trị cao hơn lá bài lớn thứ `y` của đối thủ
			2:
				Để +1 thì chết
				Vì để +1 có nghĩa là giữ bộ cũ (độ dài `x-1`) & thêm bộ mới (độ dài `x`)
			*/
			dp[x][i][j] = add(dp[x][i][j], dp[x-1][i-1][j-1]);
		}
	}
	return dp[k][n][m];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	sort(a+1, a+1+n);
	sort(b+1, b+1+m);
	cout << calc() << "\n";
	return 0;
}
