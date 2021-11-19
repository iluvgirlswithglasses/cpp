
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Nov 19 16:07:58 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <set>
using namespace std;

const int N = 1e5+7;
int n, a;
set<int> b;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a; b.insert(a);
	}
	//
	int res = 2e9+7;
	for (int i = 0; i < n; i++) {
		cin >> a;
		set<int>::iterator p = b.lower_bound(-a);
		if (p != b.end())
			res = min(res, abs(a + *p));
		if (p != b.begin()) 
			res = min(res, abs(a + *--p));
	}
	cout << res << "\n";
	return 0;
}

