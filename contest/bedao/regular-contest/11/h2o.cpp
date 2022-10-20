
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Oct 20 10:05:25 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e6+7;
int n, q;
ll  x[N], w[N], dp[N], dw[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> w[i];
		// dp[i]: chi phí di chuyển tcả các thùng nước bên trái về phía `i`
		dp[i] = dp[i-1] + dw[i-1] * (x[i] - x[i-1]);
		// dw[i]: sum w[1:i]
		dw[i] = w[i] + dw[i-1];
	}
	//
	cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		// `-dp[l]`: loại chi phí di chuyển trong khoảng [1:l)
		// `-dw[l-1]*(x[r] - x[l])`: các thùng nước trong khoảng [1:l)
		// không cần phải qua đoạn x[l:r]
		cout << dp[r] - dp[l] - dw[l-1]*(x[r] - x[l]) << "\n";
	}
	return 0;
}
