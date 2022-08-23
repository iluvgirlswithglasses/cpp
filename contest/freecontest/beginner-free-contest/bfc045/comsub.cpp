
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Aug 23 15:57:09 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

// this is like LCS, but advanced
// with rectangular area calculation combined

#define ll long long

const int N = 2e3+7, I = 1e5+7, R = 1e9+7;
int n, m, a[N], b[N];
ll  dp[N][N];

ll calc() {
	for (int i = 1; i <= n; i++) 
	for (int j = 1; j <= m; j++) {
		if (a[i] == b[j])
			dp[i][j] = ( dp[i][j-1] + dp[i-1][j] + 1 ) % R;
		else
			dp[i][j] = ( dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + R) % R;
	}
	return (dp[n][m] + 1) % R;
	//                 ^ `+ 1`: adds the case of empty subsequence
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
