
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 14 16:50:40 2022
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

#define pi pair<const int, int>
#define st first
#define nd second

int __gcd(int a, int b) {
	if (b == 0) return a;
	return __gcd(b, a%b);
}

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	return __gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		map<int, int> m;	// m[i]: final position of `i`
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			m[a] = i;
		}
		int res = -1;
		for (pi &p: m)
			for (pi &q: m)
				if (gcd(p.st, q.st) == 1) res = max(res, p.nd + q.nd);
		cout << res << "\n";
	}
	return 0;
}
