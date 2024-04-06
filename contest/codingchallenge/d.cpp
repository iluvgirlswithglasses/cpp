
/*
author:		iluvgirlswithglasses
github:		https://github.com/iluvgirlswithglasses
created:	Sat Apr  6 21:21:09 2024
style:		C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

See more about the style at:
	https://iluvgirlswithglasses.github.io/style/cpp
I were once so into competitive programming. Now they're all gone.
BTW I love Cao Nhi.
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

const int32_t N = 100+7, R = 1e9+7;
const int64_t I = 1e17+7;
int n, l, r;
int64_t a[N];

void solve()
{
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		cin >> a[i];
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

