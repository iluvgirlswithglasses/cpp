
/*
đổi đề một tí:
thao tác 2, thay vì thêm vào bên phải, mình thích thêm vào đâu cũng được
*/

#include <iostream>
#include <string>
using namespace std;

#define u64 unsigned long long
const int N = 20;
string n, po2[64];
int dp[N][N];

int compare(string &s) {
	for (int i = 1; i <= n.length(); i++) {
		for (int j = 1; j <= s.length(); j++) {
			if (n[i-1] == s[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n.length()][s.length()];
}

int calc() {
	int res = 1e9+7;
	int len = n.length()<<1;
	//
	int i = 0; string s = po2[0];
	for (; i < 64 && s.length() <= len; s = po2[++i]) {
		int match = compare(s), 
			erase = n.length() - match,
			addit = s.length() - match;
		res = min(res, erase + addit);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (u64 i = 0, _tmp=1; i < 64; i++) 
		po2[i] = to_string(_tmp<<i);
	//
	int t; cin >> t;
	while (t--) {
		cin >> n;
		cout << calc() << "\n";
	}
	return 0;
}
