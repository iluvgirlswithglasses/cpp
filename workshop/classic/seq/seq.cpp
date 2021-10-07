#include <bits/stdc++.h>
using namespace std;

//
int n, k; int * arr;
int ** dp;

// init
void init_dp() {
	// dp[i][j] length of the longest subarray in arr[0; i] with mod == j
	dp = new int*[n+1];
	for (int i = 0; i < n + 1; i++) {
		dp[i] = new int[k];
		//
		for (int j = 0; j < k; j++) dp[i][j] = -1;
	}
	dp[0][0] = 0;
}

//
void getinp() {
	ifstream inp("inp.txt");
	inp >> n >> k;
	arr = new int[n]; for (int i = 0; i < n; i++) inp >> arr[i];
	//
	init_dp();
}

// main
int calc(int len, int r) {
	if (len == 0) return dp[0][r];
	return max(
		// skip this len
		calc(len-1, r),
		// (pre + a % k) % k == r => this = pre res + 1
		calc(len-1, (r - arr[len-1]%k + k) % k) + 1
	);
}

//
int main() {
	getinp();
	cout << calc(n, 0);
	//
	system("pause");
	return 0;
}
