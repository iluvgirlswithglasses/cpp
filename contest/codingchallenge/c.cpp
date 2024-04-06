
/*
author:		iluvgirlswithglasses
github:		https://github.com/iluvgirlswithglasses
created:	Sat Apr  6 20:47:09 2024
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

const int32_t N = 1e5+7, R = 1e9+7;
const int64_t I = 1e18+7;
int64_t n, a, na, c, nc;
string s;
string padding = "0";

int64_t calc(vector<pi>& mines)
{
	vector<int> merge_len;
	for (int i = 0; i < mines.size() - 1; i++) {
		int l = mines[i].nd + 1, r = mines[i+1].st;	// [l:r)
		merge_len.push_back(r - l);
	}
	sort(all(merge_len));

	int64_t best = I;
	for (int64_t denotes = 1; denotes <= min(na, static_cast<int64_t>(mines.size())); denotes++) {
		// want to denotes `d` times -> has to merge `mines.size() - d` times
		int merges = mines.size() - denotes;

		int64_t fill_count = 0;
		for (int i = 0; i < merges; i++)
			fill_count += merge_len[i];
		if (fill_count > nc)
			continue;

		best = min(best, denotes * a + fill_count * c);
	}
	return best == I ? -1 : best;
}

void solve()
{
	cin >> n >> a >> na >> c >> nc >> s;
	s = padding + s + padding;
	vector<pi> mines;
	for (int i = 1, l; i < s.length(); i++) {
		if (s[i] == '1' && s[i-1] == '0')
			l = i;
		if (s[i] == '0' && s[i-1] == '1')
			mines.push_back({l, i - 1});	// [l:r]
	}
	if (mines.size() == 0)
		cout << "0\n";
	else
		cout << calc(mines) << "\n";
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

