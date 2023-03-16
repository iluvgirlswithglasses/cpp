
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Mar 16 18:07:47 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
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

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 1e5+7, I = 1e9+7, R = 1e9+7;
int n, a[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	/*
	if dont know anything --> each a cage
	if know               --> at worst n/2 cages for gender `a`, 1 cage for gender b
	*/
	int ans = 0, unknown = 0, alloc = 0, free = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			ans = max(ans, ++unknown + alloc);
		} else if (unknown > 0) {
			if (free == 0) {
				// gender a
				alloc += (unknown>>1) + 1;
				if (unknown&1)
					free = 1; // 1 stray gender b
				else
					free = 2; // 2 stray genders
			} else if (free == 1) {
				// gender a
				alloc += unknown>>1;
				// also gender a
				if (unknown&1)
					free++, alloc++;	// 1 more stray gender
			} else if (free == 2) {
				// gender a
				alloc += unknown>>1;
				// either gender
				if (unknown&1)
					free--;
			}
			unknown = 0;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}
