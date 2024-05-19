
/*
author:		iluvgirlswithglasses
github:		https://github.com/iluvgirlswithglasses
created:	Sat May 18 23:31:29 2024
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

const int N = 1e6+7, I = 1e9+7, R = 1e9+7;
int n;

void solve()
{
	int n, a, b;
	cin >> n >> a >> b;
	if (b < a * 2) {
		int sum = b * (n/2);
		if (n&1) sum += a;
		cout << sum << "\n";
	} else {
		int sum = a * n;
		cout << sum << "\n";
	}
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

