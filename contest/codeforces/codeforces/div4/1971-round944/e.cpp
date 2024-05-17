
/*
author:		iluvgirlswithglasses
github:		https://github.com/iluvgirlswithglasses
created:	Fri May 17 15:57:22 2024
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

const int K = 1e6+7, I = 1e9+7, R = 1e9+7;
int n, k, q;
int a[K], b[K];

void solve()
{
	cin >> n >> k >> q;
	k++;
	for (int i = 1; i < k; i++)
		cin >> a[i];
	for (int i = 1; i < k; i++)
		cin >> b[i];

	while (q--) {
		int d;
		cin >> d;

		int itr = upper_bound(a, a+k, d) - a;
		if (itr == k) {
			cout << b[k-1] << " ";
		} else {
			int pre = a[itr - 1], nxt = a[itr];
			// double speed = (double) (nxt - pre) / (b[itr] - b[itr - 1]);
			// double etime = (d - pre) / speed;
			// int ans = b[itr - 1] + static_cast<int>(etime);
			int ans = b[itr - 1] + (uint64_t) (d - pre) * (b[itr] - b[itr - 1]) / (nxt - pre);
			cout << ans << " ";
		}
	}
	cout << "\n";
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

