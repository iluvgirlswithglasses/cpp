
/*
author:		iluvgirlswithglasses
github:		https://github.com/iluvgirlswithglasses
created:	Thu May 23 18:31:35 2024
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
#define has(c, a) c.find(a) != c.end()

const int N = 1e5+7, I = (1 << 20) + 7, R = 1e9+7;
int n, f[N<<1];

int query(int l, int r)
{
	int ans = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ans |= f[l++];
		if (r & 1) ans |= f[--r];
	}
	return ans;
}

bool check(int k)
{
	int base = query(0, k);
	for (int i = 1; i <= n - k; i++)
		if (query(i, i + k) != base)
			return false;
	return true;
}

int solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> f[n + i];
	for (int i = n - 1; i > 0; i--)
		f[i] = f[i<<1] | f[i<<1|1];

	int l = 1, r = n, m;
	while (l < r) {
		m = (l + r + 0) >> 1;
		if (check(m))
			r = m;
		else
			l = m + 1;
	}
	return r;
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

