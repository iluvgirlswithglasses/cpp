
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Sep 18 16:31:29 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstdio>
using namespace std;

const int N = 2007;
const int MOV_R[4] = {+1, -1, -2, -2};
const int MOV_C[4] = {-2, -2, -1, +1};

int  m, n, q, y, x;
bool dp[N][N];	// dp[i][j] == 0 --> ai đi vào đây thì thua

bool legit(int r, int c) {
	return 1 <= r && r <= m && 1 <= c && c <= n;
}

void assign(int r, int c, int v) {
	if (legit(r, c) && dp[r][c] == 0) dp[r][c] = v;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n >> q;
	for (int d = m+n; d >= 4; d--) {
		for (int c = min(d-1, n), r = d-c; legit(r, c); c--, r++) {
			for (int t = 0; t < 4; t++)
				assign(r + MOV_R[t], c + MOV_C[t], dp[r][c]^1);
		}
	}
	while (q--) {
		cin >> y >> x;
		if (dp[y][x])
			cout << "iluvgirlswithglasses\n";
		else
			cout << "Kither\n";
	}
	return 0;
}
