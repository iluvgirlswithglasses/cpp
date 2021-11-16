
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Nov 15 18:35:48 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 3e3+7;
int r, c, h, w;
int p[N][N], f[N][N];

bool check(int mi) {
	for (int i = 1; i <= r; i++)
	for (int j = 1; j <= c; j++) {
		// auto init
		if (p[i][j] >= mi) f[i][j] = 1;
		else f[i][j] = 0;
		//
		f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1];
	}
	//
	for (int i = 1, ii = i+h-1; ii <= r; i++, ii++)
	for (int j = 1, jj = j+w-1; jj <= c; j++, jj++) {
		// basic matrix cumsum
		int cnt = f[ii][jj] - f[i-1][jj] - f[ii][j-1] + f[i-1][j-1];
		// there are more than half of the houses
		// whose have greater value than `mi`
		// --> accept
		if (cnt > h * w / 2) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> r >> c >> h >> w;
	for (int i = 1; i <= r; i++)
	for (int j = 1; j <= c; j++) {
		cin >> p[i][j];
	}
	//
	int lo = 1, hi = r*c;
	while (lo < hi) {
		int mi = (lo + hi + 1) >> 1;
		if (check(mi)) {
			lo = mi;
		} else {
			hi = mi - 1;
		}
	}
	cout << lo << "\n";
	return 0;
}

