#include <iostream>
#include <string>
using namespace std;

const int N = 3004;
string a, b, r;
int dp[N][N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b;
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	//
	int i = a.length(), j = b.length();
	while (i > 0 || j > 0) {
		if (dp[i][j] > dp[i-1][j] && dp[i][j] > dp[i][j-1]) {
			r = a[i-1] + r;
			i--; j--;
		} else if (i > 0 && dp[i-1][j] > dp[i][j-1]) {
			i--;
		} else {
			j--;
		}
	}
	cout << r << "\n";
	return 0;
}
