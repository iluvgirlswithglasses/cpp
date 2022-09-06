
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Sep  6 16:08:08 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int K = 52, N = 1e5+7, R = 1e9+7;
int k, n, dp[K][N]; // dp[i][j]: số cách tạo chuỗi độ dài `i` nếu số cuối là `j`

void radd(int &x, int y) {
	x += y;
	if (x >= R) x -= R;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int j = 1; j <= n; j++)
		dp[1][j] = 1;
	//
	for (int i = 1; i < k; i++) {
		for (int j = 1; j <= n; j++) {
			for (int m = 1; j*m <= n; m++) {
				radd(dp[i+1][j*m], dp[i][j]);
			}
		}
	}
	//
	int res = 0;
	for (int j = 1; j <= n; j++)
		radd(res, dp[k][j]);
	cout << res << "\n";
	return 0;
}
