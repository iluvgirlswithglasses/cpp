
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Aug 27 22:27:34 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define vi vector<ll>

const int N = 1e5+7;
int n;
ll  p[N];

void divide(vi &f, int l, int r) {
	ll *x = lower_bound(p+l+1, p+r+1, p[l] + (p[r] - p[l])/2);
	// f = {sum left, sum right}
	f = {*x - p[l], p[r] - *x};
	if (--x - p >= l) {
		ll a = *x - p[l], b = p[r] - *x;
		if (
			abs(a - b) < *max_element(all(f)) - *min_element(all(f))
		) f = {a, b};
	}
}

void join(vi &f, vi &g) {
	for (ll i: g) f.push_back(i);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		p[i] += p[i-1];
	}
	ll res = 1e15+7;
	vi f, g;
	for (int i = 0; i <= n; i++) {
		divide(f, 0, i);
		divide(g, i, n);
		join(f, g);
		res = min(res, *max_element(all(f)) - *min_element(all(f)));
	}
	cout << res << "\n";
	return 0;
}
