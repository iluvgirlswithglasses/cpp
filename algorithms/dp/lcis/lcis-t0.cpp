// find the longest common sequence that is also an increasing sequence
// example:
// 		a: 0 5 2 4 6
// 		b: 0 5 2 4 5
//  --> c: 0 2 4
//		a: 6 1 2 3 5
//		b: 1 6 4 2 5
//	--> c: 1 2 5

// referenced article: geeksforgeeks -> lcis
// this only work for strictly increasing sequences

#include <algorithm>
#include <iostream>
using namespace std;

/**
 * vars
 * */
const int nlim = 1e3 + 7;
const int alim = 1e9 + 7;
int m, a[nlim],
	n, b[nlim];
// dp[j] store the length of lcis ending with b[j]
int dp[nlim];

/**
 * perf
 * */
int calc() {
	//
	for (int i = 0; i < m; i++) {
		// the current length
		int cr = 0;
		for (int j = 0; j < n; j++) {
			// nếu a[i] == b[j]
			// --> max len hiện tại + 1
			if (a[i] == b[j]) 
				dp[j] = max(dp[j], cr + 1);
			// nếu a[i] > b[j]
			// --> kế thừa max len từ dp[j]
			if (a[i] > b[j]) 
				cr = max(cr, dp[j]);
		}
	}
	//
	return *max_element(dp, dp + n);
}

/**
 * drivers
 * */
int main() {
	// inp
	cin >> m >> n;
	for (int i = 0; i < m; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	// calc
	cout << calc() << endl;
	// returns
	system("pause");
	return 0;
}

