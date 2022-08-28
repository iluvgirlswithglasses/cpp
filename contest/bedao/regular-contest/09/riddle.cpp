
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Aug 28 20:22:15 2022
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
using namespace std;

const int N = 1e5+7;
int n, dp[N];
string s;
vector<int> loc[26];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; i++) {
		loc[s[i] - 'a'].push_back(i);
	}
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i-1])
			dp[i] = dp[i-1] + 1;
		else
			dp[i] = dp[i-1];
	}
	//
	long long cnt = 0;
	for (int c = 'a' - 'a'; c <= 'z' - 'a'; c++) {
		for (int i = 1; i < loc[c].size(); i++) {
			if (loc[c][i] == loc[c][i-1]+1) {
				// adj
				cnt++;
			} else {
				if (
					dp[ loc[c][i]-1 ] != dp[ loc[c][i] ] &&
					dp[ loc[c][i]-1 ] == dp[ loc[c][i-1]+1 ]
				) cnt++;
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}
