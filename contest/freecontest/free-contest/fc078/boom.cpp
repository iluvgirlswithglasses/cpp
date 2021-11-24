
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Nov 24 22:00:43 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 502;
int n, m, x, y, w, r, a[N][N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	while (m--) {
		cin >> x >> y >> w;
		a[++y][++x] += w;	// THE ONLY TIME I HAVE TO SHIFT UP X AND Y
		for (int d = 1; d < w; d++) {
			for (int i = max(x-d, 1); i <= min(x+d, n); i++) {
				if (y - d >= 1) a[y-d][i] += w - d;
				if (y + d <= n) a[y+d][i] += w - d;
			}
			for (int i = max(y-d+1, 1); i < min(y+d, n); i++) {
				if (x - d >= 1) a[i][x-d] += w - d;
				if (x + d <= n) a[i][x+d] += w - d;
			}
		}
	}
	//
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++) 
		r = max(r, a[i][j]);
	cout << r << "\n";
	return 0;
}
