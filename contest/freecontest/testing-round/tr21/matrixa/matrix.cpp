
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Oct 06 17:26:42 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
using namespace std;

const int N = 302, I = 1e9+7;
// row prefix, col prefix
int m, n, res, a[N][N], row[N][N], col[N][N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// inp
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int v; cin >> v;
			a[i][j] = v;
			row[i][j] = row[i][j-1] + v;
			col[i][j] = col[i-1][j] + v;
		}
	}
	// l, r, t, d
	for (int l = 1; l < n; l++) {
		for (int r = l+1; r <= n; r++) {
			// dòng có giá trị lớn nhất và giá trị của dòng đó 
			// trước khi duyệt tới dòng d
			int t = 1;
			int t_val = row[t][r-1] - row[t][l];		// sum (l, r);
			for (int d = 2; d <= m; d++) {
				int c_val = col[d][l] - col[t-1][l]		// sum [d, t]
						  + col[d][r] - col[t-1][r];	// sum [d, t]
				int d_val = row[d][r-1] - row[d][l];	// sum (l, r)
				res = max(res, c_val + d_val + t_val);
				//
				if (d_val + a[d][l] + a[d][r] > c_val + t_val) {
					t = d;
					t_val = d_val;
				}
			}
		}
	}
	//
	cout << res << "\n";
	return 0;
}

