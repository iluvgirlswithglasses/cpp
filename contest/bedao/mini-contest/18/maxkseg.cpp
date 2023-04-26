
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Apr 26 13:58:38 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

/**
 * @ vars
 * */
const int N = 1e5+7, K = 104;
int n, k, a[N];

// dp[k][i][usage] = best sum if use/not-use `i` in `k` segment
ll dp[K][N][2];

/**
 * @ utils
 * */
ll calc() {
	// first iteration
	dp[0][0][true] = a[0];
	for (int i = 1; i < n; i++)
		dp[0][i][true] = a[i] + max(0ll, dp[0][i-1][true]);
	//
	for (int r = 1; r < k; r++) {
		ll mxpre = 0, mxcur = 0;
		for (int i = 0; i < n; i++) {
			// include `i`
			dp[r][i][true] = a[i] + max(
				mxpre,				// make a new segment with `i`
				dp[r][i-1][true]	// lengthen `r`-th segment with `i`	
			);

			// skip `i`
			dp[r][i][false] = max(mxpre, mxcur);

			// update pre
			mxpre = max(mxpre, max(dp[r-1][i][false], dp[r-1][i][true]));
			mxcur = max(mxcur, max(dp[r][i][false], dp[r][i][true]));
		}
	}

	return max(dp[k-1][n-1][false], dp[k-1][n-1][true]);
}

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << calc() << "\n";
	/** @ deb */
	for (int r = 0; r < k; r++) {
		printf("r=%-8d", r);
		for (int i = 0; i < n; i++)
			printf("%-4d", (int) dp[r][i][false]);
		printf("\n  %-8c", ' ');
		for (int i = 0; i < n; i++)
			printf("%-4d", (int) dp[r][i][true]);
		printf("\n");
	}
	return 0;
}
