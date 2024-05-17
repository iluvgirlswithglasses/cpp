
/*
author:		iluvgirlswithglasses
github:		https://github.com/iluvgirlswithglasses
created:	Fri May 17 15:46:45 2024
style:		C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

See more about the style at:
	https://iluvgirlswithglasses.github.io/style/cpp
FYI I use Debian
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 1e6+7, I = 1e9+7, R = 1e9+7;
int n;

int calc(string& s)
{
	int ans = 0;
	for (int i = 1; i < s.length(); i++) {
		if (s[i-1] != s[i])
			ans++;
	}
	return max(2, ans);
}

void solve()
{
	string s;
	cin >> s;
	for (int i = 1; i < s.length(); i++) {
		if (s[i-1] > s[i]) {
			cout << calc(s) << "\n";
			return;
		}
	}
	cout << "1\n";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}

