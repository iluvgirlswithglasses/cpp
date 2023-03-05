
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Mar  5 22:06:00 2023
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

const int N = 2e5+7;
// lst[i]: the last time `i` re-appeared
// cnt[i]: number of iters with `i`
int n, m, a[N], p[N], v[N], lst[N<<1], cnt[N<<1];

ll calc() {
	ll ans = 0, cr = 0;
	memset(lst, 0, sizeof(lst[0])*(n+m+1));
	memset(cnt, 0, sizeof(cnt[0])*(n+m+1));
	for (int i = 1; i <= n; i++)
		lst[a[i]] = i;
	//
	for (int i = 1; i <= m; i++) {
		int pi = p[i], vi = v[i], ai = a[pi];
		// (this itr) = (last itr) - (itr without replaced item) + (itr without new item)
		if (ai != vi) {
			cnt[vi] += i - lst[vi];
			lst[ai] = i;
			int without_ai = i - cnt[ai], without_vi = i - cnt[vi];
			cr = cr - without_vi + without_ai;
		}
		a[pi] = vi;
		ans += cr + 1ll*n*i;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= m; i++)
			cin >> p[i] >> v[i];
		cout << calc() << "\n";
	}
	return 0;
}

