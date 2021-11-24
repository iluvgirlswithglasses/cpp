
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Nov 24 21:36:00 2021
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

const int I = 2e9+7;
int n, a;
int res = I;
set<int> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		set<int>::iterator p = s.lower_bound(a);
		if (p != s.end()) 
			res = min(res, *p - a);
		if (p != s.begin())
			res = min(res, a - *--p);
		s.insert(a);
	}
	cout << res << '\n';
	return 0;
}
