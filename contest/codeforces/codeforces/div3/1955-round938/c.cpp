
/*
author:		iluvgirlswithglasses
github:		https://github.com/iluvgirlswithglasses
created:	Sat May 19 10:20:35 2024
style:		C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

See more about the style at:
	https://iluvgirlswithglasses.github.io/style/cpp
FYI I use Debian
*/

#include <csignal>
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

const int32_t N = 2e5+7;
const int64_t I = 1e15+7, R = 1e9+7;
int64_t n, k, a[N];

int solve()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;

	int l = 0, r = n - 1;
	while (k > 0 && l < r) {
		int64_t& lt = a[l];
		int64_t& rt = a[r];
		auto     mn = min(lt, rt);

		if (k >= 2 * mn) {
			lt -= mn;
			rt -= mn;
			k -= 2 * mn;
		} else {
			int64_t dl = k/2, dr = k/2;
			if (k&1) dl++;
			lt -= dl;
			rt -= dr;
			k = 0;
		}

		if (lt <= 0) {
			l++;
			ans++;
		}
		if (rt <= 0) {
			r--;
			ans++;
		}
	}

	if (l == r && a[l] >= 0 && k >= a[l])
		return ans + 1;

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cout << solve() << "\n";
	}
	return 0;
}

