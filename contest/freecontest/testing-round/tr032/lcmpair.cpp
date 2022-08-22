
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Jun 22 13:21:25 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <map>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<const int, int>
#define st first
#define nd second

int n;
map<int, int> m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		m[a]++;
	}
	ll res = 0;
	for (pi& p: m) {
		ll cnt = p.nd;
		res += (cnt * (cnt-1)) >> 1;
	}
	cout << res << "\n";
	return 0;
}
