
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Aug 23 22:59:23 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

// let's see how fast is this compared to my original submission

const int N = 2e3+7, R = 1e9+7;
int n, m, a[N], b[N];
int dp[N][N];

int add(int a, int b) {
	a += b;
	if (a >= R) return a - R;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) return a + R;
	return a;
}

int calc() {
	for (int i = 1; i <= n; i++) 
	for (int j = 1; j <= m; j++) {
		if (a[i] == b[j])
			dp[i][j] = add(add(dp[i][j-1], dp[i-1][j]), 1);
		else
			dp[i][j] = sub(add(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
	}
	return add(dp[n][m], 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	cout << calc() << "\n";
	return 0;
}
