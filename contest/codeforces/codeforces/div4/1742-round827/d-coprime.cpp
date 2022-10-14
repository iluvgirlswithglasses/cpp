
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

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<const int, int>
#define st first
#define nd second

const int N = 1e6+7, I = 1e9+7, R = 1e9+7;
int n;

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
