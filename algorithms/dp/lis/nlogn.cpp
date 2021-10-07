#include <algorithm>
#include <time.h>
#include <random>
#include <iostream>
using namespace std;

// @vars
const int lim = 1e3;
int n;
int arr[lim];


// @algorithm

int nlogn_improved() {
	int * dp = new int[n+2];
	dp[0] = -lim;
	dp[n+1] = lim;
	//
	int p = 0;
	for (int i = 0; i < n; i++) {
		// binary search for the biggest number that is < arr[i]
		int l = 0, r = p;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (dp[mid] >= arr[i]) {
				r = mid - 1;
			} else {
				l = mid;
			}
		}
		// now, dp[l] is the biggest number that is < arr[i]
		if (l < p) {
			if (arr[i] < dp[l+1]) dp[l+1] = arr[i];
		} else {
			// if dp[l] < arr[i] --> assign new length
			dp[++p] = arr[i];
		}
	}
	//
	return p;
}

int nlogn() {
	int * dp = new int[n+2];
	dp[0] = -lim;
	// dp[n+1] = lim;
	for (int i = 1; i <= n+1; i++) dp[i] = lim;
	//
	for (int i = 0; i < n; i++) {
		// binary search
		int l = 0, r = n;
		while (l < r - 1) {
			int m = (l + r) >> 1;
			if (dp[m] >= arr[i]) {
				r = m;
			} else {
				l = m;
			}
		}
		// l == r
		if (arr[i] < dp[l+1]) {
			dp[l+1] = arr[i];
		}
	}
	//
	for (int i = n; i > 0; i--) {
		if (dp[i] < lim) return i;
	}
	return 0;
}

int nn() {
	int * dp = new int[n];
	dp[0] = 1;
	//
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	return *max_element(dp, dp+n);
}


// @drivers
void autoinp() {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 20;
		cout << arr[i] << " ";
	}
	cout << endl;
}

void handinp() {
	for (int i = 0; i < n; i++) cin >> arr[i];
}

int main() {
	srand((unsigned) time(0));
	while (true) {
		// getinp
		cin >> n;
		if (n == 0) return 0;
		autoinp();
		// 
		cout << nlogn_improved() << " " << nlogn() << " " << nn() << endl;
	}
	//
	system("pause");
	return 0;
}
