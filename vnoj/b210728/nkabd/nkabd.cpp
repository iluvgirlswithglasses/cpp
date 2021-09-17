#include <iostream>
using namespace std;

const int lim = 1e5;
int l, r, dp[lim+7];

int main() {
	//
	cin >> l >> r;
	//
	for (int i = 1; i <= (lim>>1|1); i++) {
		for (int j = (i<<1); j <= lim; j += i) {
			dp[j] += i;
		}
	}
	//
	int c = 0;
	for (int i = l; i <= r; i++) {
		if (dp[i] > i) c++;
	}
	cout << c << endl;
	//
	system("pause");
	return 0;
}
