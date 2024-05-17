
/*
author:		iluvgirlswithglasses
github:		https://github.com/iluvgirlswithglasses
created:	Fri May 17 15:20:47 2024
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
#define inside(i, c) c.find(i) != c.end()

const int N = 1e6+7, I = 1e9+7, R = 1e9+7;
int n;

bool solve()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a--; b--; c--; d--;
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);

	set<int> oboe, clar;
	for (int i = a + 1; i < b; i++) {
		oboe.insert(i);
	}
	for (int i = b + 1 == 12 ? 0 : b + 1; i != a; ) {
		clar.insert(i);
		if (++i >= 12) i -= 12;
	}

	return
		(inside(c, oboe) && inside(d, oboe)) ||
		(inside(c, clar) && inside(d, clar));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		if (solve())
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}

