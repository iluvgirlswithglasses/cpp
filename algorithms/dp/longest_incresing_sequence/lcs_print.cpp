#include <iostream>
using namespace std;

/**
 * vars
 * */
const int nlim = 1e3 + 7;
int m, a[nlim], 
	n, b[nlim];
int dp[nlim][nlim];

/**
 * lcs
 * */
void lcs() {
	//
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			// init
			dp[i][j] = 0;
			//
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	// return dp[m][n]
}

/**
 * restoration
 * */
// O(n+m)
void one_lcs() {
	int * common = new int[ dp[m][n] ];
	int index = dp[m][n] - 1;
	// we're going backward
	int i = m, j = n;
	while (i > 0 || j > 0) {
		if (dp[i][j] == dp[i-1][j]) {
			i--;
		} else if (dp[i][j] == dp[i][j-1]) {
			j--;
		} else {
			// caught one
			common[index--] = a[i-1];
			i--; j--;
		}
	}
	// out
	for (int i = 0; i < dp[m][n]; i++) {
		cout << common[i] << " ";
	}
	cout << endl;
	delete[] common;
}

/**
 * drivers
 * */
int main() {
	//
	int t; cin >> t;
	while (t--) {
		cin >> m >> n;
		for (int i = 0; i < m; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		//
		lcs();
		//
		one_lcs();
		cout << endl;
	}
	//
	system("pause");
	return 0;
}

