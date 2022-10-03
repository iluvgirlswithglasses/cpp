
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Oct 03 08:49:56 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <set>
using namespace std;

// instead of storing the array `a`
// i'll store the distance of each element to `b`

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e5+7, I = 1e9+7;
int n, m, k, a[N];	// a[n], b[m]
set<int> b;

int f[N<<1];

void build() {
	for (int i = 0; i < n; i++)
		f[i+n] = a[i];
	for (int i = n-1; i > 0; i--)
		f[i] = min(f[i<<1], f[i<<1|1]);
}

int get(int l, int r) {
	int mn = I;
	for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if (l&1) mn = min(mn, f[l++]);
		if (r&1) mn = min(mn, f[--r]);
	}
	return mn;
}

void to_dist() {
	for (int i = 0; i < n; i++) {
		int x = I;
		set<int>::iterator p = b.lower_bound(a[i]);
		if (p != b.end()) x = min(x, abs(a[i] - *p));
		if (p != b.begin()) x = min(x, abs(a[i] - *--p));
		a[i] = x;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		b.insert(x);
	}
	to_dist();
	build();
	while (k--) {
		int l, r; cin >> l >> r;
		cout << get(--l, r) << "\n";
	}
	return 0;
}
