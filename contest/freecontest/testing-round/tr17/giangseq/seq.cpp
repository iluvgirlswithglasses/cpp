#include <iostream>
using namespace std;

/**
 * lim
 * */
const int nlim = 2e3;
const int alim = 1e9;

/**
 * vars
 * */
int n, k, arr[nlim];
int dp[nlim];

/**
 * drivers
 * */
int main() {
	// inp
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	// calc
	for (int i = 1; i < n; i++) {
		dp[i] = min(
			dp[i-1], abs(arr[i] - arr[i-1])
		);
	}
	// returns
	cin >> n;
	return 0;
}
