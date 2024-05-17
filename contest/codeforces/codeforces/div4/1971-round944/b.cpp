
/*
author:		iluvgirlswithglasses
github:		https://github.com/iluvgirlswithglasses
created:	Fri May 17 15:16:40 2024
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

void solve()
{
	string s; cin >> s;
	map<char, int> dct;
	for (int i = 0; i < s.length(); i++) {
		dct[s[i]] = i;
	}

	if (dct.size() <= 1) {
		cout << "NO\n";
		return;
	}

	auto a = dct.begin();
	auto b = ++dct.begin();
	swap(s[a->second], s[b->second]);
	cout << "YES\n" << s << "\n";
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

