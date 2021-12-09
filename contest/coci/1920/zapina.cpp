
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Dec  9 22:16:09 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstdio>	// debug
using namespace std;

/**
 * @ defs
 * */
#define ll long long
const int N = 400, R = 1e9+7;

int add(int a, int b) {
	int c = a + b;
	if (c >= R) return c - R;
	return c;
}

int mul(int a, int b) {
	return (ll) a * b % R;
}

int apowb(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	int c = apowb(a, b>>1);
	if (b&1) return mul(a, mul(c, c));
	return mul(c, c);
}

/**
 * @ vars
 * 
 * nCk = (n-1)C(k-1) + (n-1)Ck
 * */
int n, nCk[N][N];
int dp[N][N];

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	nCk[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		nCk[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			nCk[i][j] = add(nCk[i-1][j-1], nCk[i-1][j]);
		}
	}
	//
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= n; j++)
	for (int k = 0; k <= j; k++)
	if (k != i) {
		dp[i][j] = add(dp[i][j], mul(dp[i-1][j-k], nCk[j][k]));
	}
	// số cách chọn - số cách chọn k ai thích
	int res = (apowb(n, n) - dp[n][n] + R) % R;
	cout << res << "\n";
	return 0;
}
