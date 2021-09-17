#include <algorithm>
#include <iostream>
using namespace std;

const int alim = 1e9+7;
const int nlim = 2e5+7;
int n, arr[nlim], dp[nlim];

int calc() {
	//
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			// there can be (... && arr[i] > arr[j]) here but arr is sorted
			if (dp[i] < dp[j] + 1 && arr[i] <= arr[j]*2) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	return *max_element(dp, dp + n);
}

int main() {
	// inp
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	//
	cout << calc() << endl;
	// returns
	// cin >> n;
	return 0;
}
