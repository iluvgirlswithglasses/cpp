
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Nov 26 15:02:58 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e3+7;
vector<string> x, y;
int a, b, dp[N][N];

int lcs() {
	for (int i = 1; i <= x.size(); i++)
	for (int j = 1; j <= y.size(); j++) {
		if (x[i-1] == y[j-1]) {
			dp[i][j] = dp[i-1][j-1] + 1;
		} else {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[x.size()][y.size()];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b;
	x.resize(b-a+1);
	for (int i = a; i <= b; i++) x[i-a] = to_string(i);
	y = x;
	sort(y.begin(), y.end());
	//
	cout << x.size() - lcs() << "\n";
	return 0;
}
