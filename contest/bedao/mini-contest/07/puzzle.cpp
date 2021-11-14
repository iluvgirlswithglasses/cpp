
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 14 21:38:43 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int x, n, m;
		cin >> x >> n >> m;
		//
		if (m < n) swap(m, n);
		//
		vector<int> dp(m, 1);
		for (int i = 1; i < n; i++) {
			//
			dp[i] = dp[i]<<1;
			for (int j = i+1; j < m; j++) {
				dp[j] += dp[j-1];
			}
		}
		cout << dp[m-1] << "\n";
	}
	return 0;
}

