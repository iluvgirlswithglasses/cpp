/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep 30 20:55:42 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define ll long long

const int N = 1e5+7;
int n, a[N], dp[26][N];

void read() {
	memset(dp, -1, sizeof(dp));
	string s; cin >> s;
	n = s.length();
	for (int i = 0; i < n; i++)
		a[i] = s[i] - 'a';
}

void gen() {
	for (int c = 0; c < 26; c++)
	for (int i = 0; i < n; i++) {
		if (c == a[i])
			dp[c][i] = i;
		else
			dp[c][i] = i > 0 ? dp[c][i-1] : -1;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	read();
	gen();
	ll res = 0;
	for (int c = 0; c < 26; c++)
	for (int i = n-1; i >= 0; i--) 
	if (c != a[i] && dp[c][i] != -1) {
		int left = dp[a[i]][i-1];
		if (left == -1)
			res++;
		else
			res += left < dp[c][i];
	}
	cout << res << "\n";
	return 0;
}