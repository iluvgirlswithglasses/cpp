#include <iostream>
using namespace std;

const int nlim = 1e3+1;
const int mlim = 1e3+1;
int n, m, w[nlim], v[nlim], dp[mlim];

int calc() {
	for (int i = 0; i < n; i++) {
		for (int j = m; j >= 0; j--) {
			int pre = j - w[i];
			if (pre < 0) break;
			dp[j] = max(dp[j], dp[pre] + v[i]);
		}
	}
	return dp[m];
}

int main() {
	//
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	//
	cout << calc() << endl;
	//
	system("pause");
	return 0;
}

