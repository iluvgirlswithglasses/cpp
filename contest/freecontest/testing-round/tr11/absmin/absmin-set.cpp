
// a better sol

/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Oct 07 11:55:55 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <set>
using namespace std;

const int N = 2e5+7, I = 2e9+7;
set<int> s;
int n, v;
int res = I;

void uassign(set<int>::iterator &p) {
	if (p != s.end())
		res = min(res, abs(v - *p));
}

void dassign(set<int>::iterator &p) {
	if (p != s.begin())
		res = min(res, abs(v - *--p));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> v;
	s.insert(v);
	//
	for (int i = 1; i < n && res != 0; i++) {
		cin >> v;
		set<int>::iterator p = s.lower_bound(v);
		uassign(p);
		dassign(p);
		s.insert(v);
	}
	cout << res << "\n";
	return 0;
}

