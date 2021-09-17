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

//
int calc() {
	for (int i = 1; i < n + 1; i++) {	// don't need to check for i == 0
		for (int j = 0; j < k; j++) {
			dp[i][j] = max(
				dp[i-1][j],		// skip arr[i-1], use previous result
				dp[i-1][ (k + j - (arr[i-1] % k)) % k ] + 1
			);
		}
	}
	//
	return dp[n][0];
}

//
int main() {
	getinp();
	init_dp();
	//
	cout << calc() << endl;
	system("pause");
	return 0;
}
