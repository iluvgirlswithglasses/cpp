#include <algorithm>
#include <iostream>
using namespace std;

const int alim = 1e9+7;
const int nlim = 2e5+7;
int n, arr[nlim];
int p, dp[nlim];

// given array is sorted
int calc() {
	int res = 0;
	//
	for (int i = 0; i < n; i++) {
		int j = i;
		while (
			j + 1 < n && arr[j+1] <= (arr[j] << 1)
		) j++;
		res = max(res, j - i + 1);
		i = j;
	}
	//
	return res;
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
