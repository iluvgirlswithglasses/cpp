
/*
author:		iluvgirlswithglasses
github:		https://github.com/iluvgirlswithglasses
created:	Sat May 18 23:37:35 2024
style:		C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

See more about the style at:
	https://iluvgirlswithglasses.github.io/style/cpp
FYI I use Debian
*/

#pragma GCC optimize ("O3")

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

const int N = 507, I = 2e9+7, R = 1e9+7;
int n, m, c, d;
map<int, int> s;

bool solve()
{
	cin >> n >> c >> d;
	m = n * n;

	s.clear();
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		s[x]++;
	}
	int a = s.begin()->first;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int expect = a + i*c + j*d;
			if (s[expect] == 0)
				return false;
			s[expect]--;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		if (solve())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}

