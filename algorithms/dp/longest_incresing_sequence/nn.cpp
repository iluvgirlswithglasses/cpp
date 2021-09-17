// nlogn-approaching version
// only for strictly increasing arrays

#include <iostream>
using namespace std;

//
const int lim = 1e4;
const int INF = 1e4;
int n;
int arr[lim], dp[lim];

//
void calc() {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n+1; j++) {
			if (dp[j-1] < arr[i] && arr[i] < dp[j]) {
				dp[j] = arr[i];
			}
		}
	}
}

//
int main() {
	// getinp
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	// prepare
	dp[0] = -INF;
	for (int i = 1; i <= n; i++) dp[i] = INF;
	//
	calc();
	// result
	for (int i = n; i > 0; i--) {
		if (dp[i] < INF) {
			cout << i << endl;
			break;
		}
	}
	//
	system("pause");
	return 0;
}
