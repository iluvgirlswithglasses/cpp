
/*
author:		iluvgirlswithglasses
github:		https://github.com/iluvgirlswithglasses
created:	Fri May 17 16:53:54 2024
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
#define inside(i, c) c.find(i) != c.end()

const int N = 1e6+7, I = 1e9+7, R = 1e9+7;
int n;
vector<int64_t> sqr;

void solve()
{
	int64_t ans = 0;

	int64_t r;
	cin >> r;
	int64_t r2 = r * r;
	int64_t t2 = (r + 1) * (r + 1);

	for (int64_t y = -r; y <= r; y++) {
		int64_t l2 = r2 - y*y;	// lowerbound ** 2
		int64_t u2 = t2 - y*y;

		// any int sol is a sol
		auto low = lower_bound(sqr.begin(), sqr.end(), l2);
		auto upp = lower_bound(low, sqr.end(), u2);
		ans += (upp - low) << 1;	// top & down
	}
	ans -= 2;	// left & right most coords

	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	constexpr size_t lim = 1e5 + 7;
	sqr.reserve(lim);
	for (size_t i {}; i < lim; i++)
		sqr.push_back(i * i);

	int tt; cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}

