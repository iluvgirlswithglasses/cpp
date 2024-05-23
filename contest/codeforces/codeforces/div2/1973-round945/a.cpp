
/*
author:		iluvgirlswithglasses
github:		https://github.com/iluvgirlswithglasses
created:	Thu May 23 18:25:27 2024
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

const int N = 1e6+7, I = 1e9+7, R = 1e9+7;
int a[3];

int solve()
{
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum & 1)
		return -1;

	int ans = 0;
	while (a[0] > 0) {
		ans++;
		a[0]--;
		if (a[2] > a[1])
			a[2]--;
		else
			a[1]--;
	}
	return ans + min(a[2], a[1]);
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

