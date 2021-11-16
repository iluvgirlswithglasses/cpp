
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Nov 15 20:27:03 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <stdio.h>

#define N 3007
int r, c, h, w, half;
int p[N][N], f[N][N];

int check(int mi) {
	for (int i = 1; i <= r; i++)
	for (int j = 1; j <= c; j++) {
		// auto init
		f[i][j] = (p[i][j] >= mi);
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
		if (cnt > half) return 1;
	}
	return 0;
}

int main() {
	scanf("%d %d %d %d", &r, &c, &h, &w);
	half = h*w>>1;
	for (int i = 1; i <= r; i++)
	for (int j = 1; j <= c; j++)
		scanf("%d", &p[i][j]);
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
	printf("%d\n", lo);
	return 0;
}

