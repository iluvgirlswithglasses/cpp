
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Sep 29 15:08:23 2022
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

const ll I = 1e18;
ll c[3] = {2, 3, 5};
vector<ll> v = {1};

void gen(ll cr, ll ic) {
	for (int i = ic; i < 3; i++) {
		ll x = cr * c[i];
		if (x > I) return;
		v.push_back(x);
		gen(x, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	gen(1, 0);
	sort(all(v));
	//
	int t; cin >> t;
	while (t--) {
		ll x; cin >> x;
		vector<ll>::iterator p = find(all(v), x);
		if (p == v.end())
			cout << "Not in sequence\n";
		else
			cout << p - v.begin() + 1 << "\n";
	}
	return 0;
}
