
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

/**
 * vars
 * */
const int nlim = 1507;
const int alim = 1e9+7;
int m, a[nlim], 
	n, b[nlim];

/**
 * perf
 * */
bool comparator(int x, int y) {
	return (x << 1) <= y;
}

int lcs2x() {
	// dp[j] stores the max len of the lcis that ends with b[j]
	vector<int> dp(n, 0);
	//
	for (int i = 0; i < m; i++) {
		int maxlen = 0;
		for (int j = 0; j < n; j++) {
			int pre = maxlen;
			//
			if (comparator(b[j], a[i])) 
				maxlen = max(maxlen, dp[j]);
			// if find another piece in common sequence
			if (a[i] == b[j]) 
				dp[j] = pre+1;
		}
	}
	//
	return *max_element(dp.begin(), dp.end());
}

/**
 * drivers
 * */
int main() {
	int t; cin >> t;
	while (t--) {
		// inp
		cin >> m >> n;
		for (int i = 0; i < m; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		// calc
		cout << lcs2x() << endl;
	}
	//
	return 0;
}

