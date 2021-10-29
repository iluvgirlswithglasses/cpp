
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 29 13:55:02 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
using namespace std;

#define ll long long

const int N = 507;
int m, n;

ll res = -1e18, a[N][N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++) {
		cin >> a[i][j];
		res = max(res, a[i][j]);
		a[i][j] += a[i][j-1];
	}
	//
	for (int l = 1; l <= n; l++)
	for (int r = l; r <= n; r++) {
		ll val = 0;
		for (int d = 1; d <= m; d++) {
			val += a[d][r] - a[d][l-1];
			if (val > 0) {
				res = max(res, val);
			} else {
				val = 0;
			}
		}
	}
	cout << res << "\n";
	return 0;
}

