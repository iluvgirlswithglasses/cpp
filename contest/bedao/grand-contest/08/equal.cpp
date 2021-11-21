
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 21 10:19:53 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
using namespace std;

const int S2I = 1e3+7;
bool e[S2I];
int  p[S2I], pcnt;

/**
 * prime numbers
 * */
void eratos() {
	for (int i = 2; i < S2I; i++) if (e[i] == 0) {
		p[pcnt++] = i;
		for (int j = i*i; j < S2I; j+=i) e[i] = 1;
	}
}

vector<int> fact(int n) {
	vector<int> res;
	for (int _i = 0, i = p[_i]; i * i <= n; i = p[++_i]) {
		while (n % i == 0) {
			res.push_back(i);
			n /= i;
		}
	}
	if (n > 1) res.push_back(n);
	return res;
}

/**
 * utils
 * */
int lcs(vector<int> a, vector<int> b) {
	int n = a.size(),
		m = b.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	//
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		if (a[i-1] == b[j-1]) {
			dp[i][j] = dp[i-1][j-1] + 1;
		} else {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int k = dp[n][m];
	return max(n - k, m - k);
}

/**
 * drivers
 * */
int a, b;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	eratos();
	//
	int t; cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << lcs(fact(a), fact(b)) << "\n";
	}
	return 0;
}

