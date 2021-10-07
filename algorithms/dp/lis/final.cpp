#include <iostream>
#include <random>
#include <time.h>
using namespace std;


// @vars
const int lim = 1e4;	// lim(n) = lim(arr[i])
int n, arr[lim];


// @algorithms
int nlogn() {
	// p = marked indexes in dp
	// if (p == 0) --> only dp[0] is marked
	// if (p == n) --> dp[0...n] is marked
	// when this function returns, p will become the max len of the LIS
	int p = 0, dp[n+2];
	dp[0] = -lim;
	dp[n+1] = lim;
	//
	for (int i = 0; i < n; i++) {
		// since dp is an increasing array, 
		// we can perform binary search to find biggest number that is < arr[i]
		int l = 0, r = p;
		while (l < r) {
			int m = (l + r + 1) >> 1;
			// subsequence[i] < subsequence[i+1]
			if (dp[m] < arr[i]) {
				l = m;
			} else {
				// with the above comparison
				// we exclude all dp[:] which >= arr[i]
				r = m - 1;
			}
		}
		//
		if (l < p) {
			if (arr[i] < dp[l+1]) dp[l+1] = arr[i];
		} else {
			dp[++p] = arr[i];
		}
	}
	// the marked indexes == the length
	return p;
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
		cout << nlogn() << endl;
	}
	//
	system("pause");
	return 0;
}

