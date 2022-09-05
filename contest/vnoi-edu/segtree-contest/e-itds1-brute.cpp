
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep  5 14:30:32 2022
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

// despite the vulnerable af while loop below
// this is still an AC solution

#define all(c) c.begin(), c.end()
#define pi pair<int, int>
#define st first
#define nd second
#define mk make_pair

const int N = 1e5+7, I = 1e9+7;
int n, q, a[N];
multiset<pi> f;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f.insert(mk(a[i], i));
	}
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int i, v; cin >> i >> v; 
			f.erase(mk(a[i], i));
			a[i] = v;
			f.insert(mk(a[i], i));
		} else if (t == 2) {
			int l, r, k; cin >> l >> r >> k;
			multiset<pi>::iterator p = f.lower_bound(mk(k, l));
			// this while loop can easily go to edge case
			while (p != f.end()) {
				if (l <= p->nd && p->nd <= r) break;
				p++;
			}
			if (p != f.end())
				cout << p->st << "\n";
			else
				cout << "-1\n";
		}
	}
	return 0;
}
