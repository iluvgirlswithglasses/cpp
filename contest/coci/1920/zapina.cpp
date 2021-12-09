
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Dec  8 17:43:52 2021
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
	return (ll) (a * b) % R;
}

/**
 * @ vars
 * 
 * nCk = (n-1)C(k-1) + (n-1)Ck
 * */
int n, nCk[N][N];
int cache[2][N][N];

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
	for (int i = 1; i <= n; i++) {
		/* give `i` jobs to... */
		
		for (int j = 1; j <= n; j++) {
			/* choose `j`-th programmer */

			/* discard `j`-th programmer */

		}
	}
	return 0;
}
