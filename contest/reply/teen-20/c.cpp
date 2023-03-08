
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Mar  8 16:57:46 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 1e5+7, P = 1e5+7, M = 1e9+7;
const ll  I = 1e14+7;	// 1e9 * 1e5
int n, k;
ll  required, p[N], s[N], a[N];

bool check(ll m) {
	// a[i]: tasks done by `i` in `m` time
	for (int i = 0; i < n; i++)
		a[i] = (m - p[i]) / s[i];

	ll ans = 0;		// tasks done
	sort(a, a+n, [](ll i, ll j){ return i > j; });
	for (int i = 0; i < k; i++) ans += a[i];
	return ans >= required;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	for (int t = 1; t <= tt; t++) {
		cin >> n >> k >> required;
		for (int i = 0; i < n; i++) 
			cin >> p[i] >> s[i];
		ll l = 0, r = I;
		while (l < r) {
			ll m = (l + r + 0) >> 1;
			if (check(m)) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		cout << "Case #" << t << ": " << r << "\n";
	}
	return 0;
}
