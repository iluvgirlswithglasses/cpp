
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Nov 04 10:54:06 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 1e5+7;
// f[i]: segtree max
// g[i]: segtree min
int n, q, f[N<<1], g[N<<1];

void build() {
	for (int i = n-1; i > 0; i--) {
		f[i] = max(f[i<<1], f[i<<1|1]);
		g[i] = min(g[i<<1], g[i<<1|1]);
	}
}

int mxquery(int l, int r) {
	int res = 0;
	for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if (l&1) res = max(res, f[l++]);
		if (r&1) res = max(res, f[--r]);
	}
	return res;
}

int mnquery(int l, int r) {
	int res = N;
	for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if (l&1) res = min(res, g[l++]);
		if (r&1) res = min(res, g[--r]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		f[i+n] = g[i+n] = x;
	}
	build();
	while (q--) {
		int l, r; cin >> l >> r;
		if (mxquery(l-1, r) - mnquery(l-1, r) == r - l)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
