/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 26 18:53:53 2022
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

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		s.insert(x);
	}
	int res = 2e9+7;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		set<int>::iterator p = s.lower_bound(x);
		if (p != s.end()) res = min(res, *p - x);
		if (p != s.begin()) res = min(res, x - *--p);
	}
	cout << res << "\n";
	return 0;
}

